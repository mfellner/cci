/*
 * Copyright 2014, Maximilian Fellner
 */

package at.mfellner.cci.test;

import at.mfellner.cci.TupleTree;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import static org.junit.Assert.*;

@RunWith(JUnit4.class)
public class TestTupleTree {
  @Test
  public void testEmptyTree() {
    TupleTree tree = new TupleTree();
    assertEquals("", tree.toString());
  }

  @Test
  public void testOneTuple() {
    TupleTree tree = new TupleTree();
    tree.insert(new TupleTree.Tuple("father", "child"));
    assertEquals("father\n└── child", tree.toString());
  }

  @Test
  public void testRootWithTwoConsecutiveChildren() {
    TupleTree tree = new TupleTree();
    tree.insert(new TupleTree.Tuple("A", "B"));
    tree.insert(new TupleTree.Tuple("B", "C"));
    assertEquals("A\n└── B\n    └── C", tree.toString());
  }

  @Test
  public void testRootWithTwoAdjacentChildren() {
    TupleTree tree = new TupleTree();
    tree.insert(new TupleTree.Tuple("R", "A"));
    tree.insert(new TupleTree.Tuple("R", "B"));
    assertEquals("R\n├── A\n└── B", tree.toString());
  }

  @Test
  public void testOrphanedDanglingTuple() {
    TupleTree tree = new TupleTree();
    tree.insert(new TupleTree.Tuple("A", "B"));
    tree.insert(new TupleTree.Tuple("C", "D"));
    assertEquals("A\n└── B", tree.toString());
  }

  @Test
  public void testConnectDanglingTuple() {
    TupleTree tree = new TupleTree();
    tree.insert(new TupleTree.Tuple("A", "B"));
    tree.insert(new TupleTree.Tuple("C", "D"));
    tree.insert(new TupleTree.Tuple("B", "C"));
    assertEquals("A\n└── B\n    └── C\n        └── D", tree.toString());
  }

  @Test
  public void testSetNewHead() {
    TupleTree tree = new TupleTree();
    tree.insert(new TupleTree.Tuple("B", "C"));
    tree.insert(new TupleTree.Tuple("A", "B"));
    assertEquals("A\n└── B\n    └── C", tree.toString());
  }

  @Test
  public void testComplexTree() {
    TupleTree tree = new TupleTree();
    tree.insert(new TupleTree.Tuple("/", "home"));
    tree.insert(new TupleTree.Tuple("/", "opt"));
    tree.insert(new TupleTree.Tuple("/", "usr"));
    tree.insert(new TupleTree.Tuple("/", "etc"));
    tree.insert(new TupleTree.Tuple("home", "max"));
    tree.insert(new TupleTree.Tuple("home", "sam"));
    tree.insert(new TupleTree.Tuple("usr", "bin"));
    tree.insert(new TupleTree.Tuple("usr", "local"));
    tree.insert(new TupleTree.Tuple("local", "lib"));
    assertEquals("/\n" +
        "└── home\n" +
        "    ├── max\n" +
        "    └── sam\n" +
        "├── opt\n" +
        "└── usr\n" +
        "    ├── bin\n" +
        "    └── local\n" +
        "        └── lib\n" +
        "└── etc", tree.toString());
//    System.out.println(tree);
  }

  @Test
  public void testContains() {
    TupleTree tree = new TupleTree();
    tree.insert(new TupleTree.Tuple("A", "B"));
    assertTrue(tree.contains("A"));
    assertTrue(tree.contains("B"));
    assertFalse(tree.contains("C"));
  }

  @Test
  public void testFatherOf() {
    TupleTree tree = new TupleTree();
    tree.insert(new TupleTree.Tuple("A", "B"));
    tree.insert(new TupleTree.Tuple("B", "C"));
    assertEquals("", tree.fatherOf("A"));
    assertEquals("A", tree.fatherOf("B"));
    assertEquals("B", tree.fatherOf("C"));
  }

  @Test
  public void testChildrenOf() {
    TupleTree tree = new TupleTree();
    tree.insert(new TupleTree.Tuple("R", "A"));
    tree.insert(new TupleTree.Tuple("R", "B"));
    tree.insert(new TupleTree.Tuple("R", "C"));
    assertEquals("[A, B, C]", tree.childrenOf("R"));
    assertEquals("[]", tree.childrenOf("A"));
  }

  @Test
  public void testDuplicateTupleShouldFail() {
    TupleTree tree = new TupleTree();
    tree.insert(new TupleTree.Tuple("A", "B"));
    try {
      tree.insert(new TupleTree.Tuple("A", "B"));
      assertFalse(true);
    } catch (TupleTree.TupleTreeError err) {
      assertNotNull(err.getMessage());
    }
  }

  @Test
  public void testChildWithDifferentFatherShouldFail() {
    TupleTree tree = new TupleTree();
    tree.insert(new TupleTree.Tuple("A", "B"));
    try {
      tree.insert(new TupleTree.Tuple("Z", "B"));
      assertFalse(true);
    } catch (TupleTree.TupleTreeError err) {
      assertNotNull(err.getMessage());
    }
  }

  @Test
  public void testDuplicateChildNodeShouldFail() {
    TupleTree tree = new TupleTree();
    tree.insert(new TupleTree.Tuple("R", "A"));
    tree.insert(new TupleTree.Tuple("R", "B"));
    tree.insert(new TupleTree.Tuple("B", "C"));
    try {
      tree.insert(new TupleTree.Tuple("A", "C"));
      assertFalse(true);
    } catch (TupleTree.TupleTreeError err) {
      assertNotNull(err.getMessage());
    }
  }
}
