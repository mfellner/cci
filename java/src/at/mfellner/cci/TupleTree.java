/*
 * Copyright 2014, Maximilian Fellner
 */

package at.mfellner.cci;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * TupleTree is a dumb and basic tree for unique String nodes.
 * Unique nodes are to be inserted as father-child tuples.
 * Insertion and retrieval is O(1).
 */
public class TupleTree {

  public static class TupleTreeError extends RuntimeException {
    public TupleTreeError(String message) {
      super(message);
    }
  }

  public static class Tuple {
    private final String mFather;
    private final String mChild;

    public Tuple(String father, String child) {
      mFather = father;
      mChild = child;
    }
  }

  private class Node {
    final String mName;
    String mFather;
    final List<String> mChildren = new ArrayList<>();

    Node(String name) {
      mName = name;
    }

    void setFather(String father) {
      mFather = father;
    }

    void addChild(String child) {
      mChildren.add(child);
    }

    boolean hasFather() {
      return mFather != null;
    }

    boolean hasChild(String child) {
      return mChildren.contains(child);
    }

    boolean hasChildren() {
      return mChildren.size() > 0;
    }

    boolean isLastChild() {
      if (mFather != null && mNodes.containsKey(mFather)) {
        List<String> fatherChildren = mNodes.get(mFather).mChildren;
        int index = fatherChildren.indexOf(mName);
        return index != -1 && index == fatherChildren.size() - 1;
      } else {
        return false;
      }
    }
  }

  private final Map<String, Node> mNodes = new HashMap<>();
  private Node mHead;

  public TupleTree() {
  }

  public boolean contains(String node) {
    return mNodes.containsKey(node);
  }

  public String fatherOf(String node) {
    String father = mNodes.get(node).mFather;
    return father != null ? father : "";
  }

  public String childrenOf(String node) {
    return mNodes.get(node).mChildren.toString();
  }

  public void insert(Tuple tuple) {
    Node father = new Node(tuple.mFather);
    Node child = new Node(tuple.mChild);
    father.addChild(child.mName);
    child.setFather(father.mName);

    if (mHead == null) {
      mHead = father;
    }

    Node existingFather = mNodes.get(father.mName);
    Node existingChild = mNodes.get(child.mName);

    if (existingFather != null) {
      if (existingChild == null && !existingFather.hasChild(child.mName)) {
        // attach new child tow existing father
        existingFather.addChild(child.mName);
        mNodes.put(child.mName, child);
      } else if (existingChild != null && !existingChild.hasFather() && !existingFather.hasChild(child.mName)) {
        // connect existing father and child
        existingFather.addChild(existingChild.mName);
        existingChild.setFather(existingFather.mName);
      } else {
        throw new TupleTreeError("Node cannot have duplicate children.");
      }
    } else if (existingChild == null) {
      // new dangling tuple
      mNodes.put(father.mName, father);
      mNodes.put(child.mName, child);
    } else if (existingChild.mName.equals(mHead.mName)) {
      // set new tree head
      mHead = father;
      mNodes.put(father.mName, father);
      existingChild.setFather(father.mName);
    } else {
      throw new TupleTreeError("Cannot insert child with different father.");
    }
  }

  private void walkTree(String nodeName, int depth, StringBuilder builder, Map<String, Boolean> visited) {
    if (nodeName != null && mNodes.containsKey(nodeName)) {
      Node node = mNodes.get(nodeName);
      if (node.mFather != null) {
        builder.append("\n");
        for (int i = 0; i < depth - 1; i++) {
          builder.append("    ");
        }
        if (node.isLastChild() || node.hasChildren()) {
          builder.append("└── ");
        } else {
          builder.append("├── ");
        }
      }
      builder.append(node.mName);
      visited.put(node.mName, true);
      node.mChildren.stream().filter(n -> !visited.getOrDefault(n, false))
          .forEach(n -> walkTree(n, depth + 1, builder, visited));
    }
  }

  @Override
  public String toString() {
    if (mHead != null) {
      StringBuilder builder = new StringBuilder();
      walkTree(mHead.mName, 0, builder, new HashMap<>());
      return builder.toString();
    } else {
      return "";
    }
  }
}
