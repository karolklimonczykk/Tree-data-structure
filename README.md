# Tree data structure
 Defining, using structures, formulating binary search tree (BST) and AVL algorithms with implementation in C++.
<h2>Tree Terminologies</h2>
<ul>
 <li><b>Tree</b> - A tree is a dynamic data structure consisting of a node element, containing
indication of a finite number of disjoint nodes constituting subtrees of a given node.</li>
 
 <li><b>Root</b> - The initial node (the highest one)</li>
 <li><b>Leaf</b> - An element that has no children (pointers to others nodes)</li>
 <li><b>Node</b> - An element that is not a leaf or a root </li>
 <li><b>Depth of a Node</b> - The root of the tree is at level 0 and each child node is at level one higher.</li>
 <li><b>Degree of a node</b> - The number of direct descendants of the node.</li>
 <li><b>Degree of a tree</b> - Maximum degree of all nodes. Degree zero nodes have no children and are called leaves.</li>
 <li><b>Height of a node</b> - The number of edges from the node to the deepest leaf (ie. the longest path from the node to a leaf node).</li>
 <li><b>Height of a tree</b> - Maximum height of all nodes. The longest path starting from the root node.</li>
 <br>
 <p align="center"><img src="https://media.geeksforgeeks.org/wp-content/uploads/20221124153129/Treedatastructure.png" alt="terminologies" width="80%"></p>
</ul>
<h2>Binary tree</h2>
<p>is a type of data structure consisting of nodes connected by edges, where each node has at most two children, called left and right subtrees.</p>
<p>To implement a binary tree we need two types of data:
 <ul>
  <li>node structure, containing information about the node value, pointers to left and right subtrees,</li>
  <li>a pointer to the root of the tree, i.e. the node from which we start the search.</li>
 </ul>
 The required variables are a pointer to the root of the tree and variables representing the values ​​of the nodes that
we will be adding to the tree.
</p>
<p align="center"><img src="https://media.geeksforgeeks.org/wp-content/uploads/20221124174432/binary.png" alt = "binary tree" width="30%" height="100%"></p>
 <ul>
  <li>Node 1 is the root node</li>
  <li>1 is the parent of 2 and 3</li>
  <li>2 and 3 are siblings</li>
  <li>4, 5, 6, and 7 are the leaf nodes</li>
  <li>1 and 2 are the ancestors of 5</li>
  <li>The height of a tree is 2 (e.g. path from 1 to 4)</li>
  <li>The degree of a tree is 2 (e.g. 2 has two descendants (4 and 5) )</li>
 </ul>
<h2>References</h2>
<ul>
  <li>Images are taken from <a href="https://www.geeksforgeeks.org/introduction-to-tree-data-structure-and-algorithm-tutorials/">here</a></li>
  <li>GIFs are taken from <a href="https://github.com/kdn251/interviews">here</a></li>
</ul>
