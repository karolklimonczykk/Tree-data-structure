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
<p>Binary tree is a type of data structure consisting of nodes connected by edges, where each node has at most two children, called left and right subtrees.</p>
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
<h2>Tree Traversal Techniques</h2>
<p><b>Preorder Traversal</b> - involves visiting a node, going to its left subtree and
recursively calling the algorithm for the left subtree and then moving to the right one
subtree and recursively call the algorithm for the right subtree.
<ol>
 <li>Visit the root.</li>
 <li>Recursively call the algorithm for the left subtree.</li>
 <li>Recursively call the algorithm for the right subtree.</li>
</ol>
</p>
<p align="center"><img src="https://i.imgur.com/2C61eSE.png" alt="tree" height="25%" width="25%"><br>Preorder traversal of binary tree: 2,1,3</p>
<br><br>
<p><b>Postorder Traversal</b> - involves recursively calling the algorithm for the left subtree, then for the right subtree and visiting the node.
<ol>
 <li>Recursively call the algorithm for the left subtree.</li>
 <li>Recursively call the algorithm for the right subtree.</li>
 <li>Visit the root.</li>
</ol>
</p>
<p align="center"><img src="https://i.imgur.com/2C61eSE.png" alt="tree" height="25%" width="25%"><br>Postorder traversal of binary tree: 1,3,2</p>
<br><br>
<p><b>Inorder Traversal</b> - involves recursively calling the algorithm for the left subtree, visiting the node, and recursively calling the algorithm for the right subtree.
<ol>
 <li>Recursively call the algorithm for the left subtree.</li>
 <li>Visit the root.</li>
 <li>Recursively call the algorithm for the right subtree.</li>
</ol>
</p>
<p align="center"><img src="https://i.imgur.com/2C61eSE.png" alt="tree" height="25%" width="25%"><br>Inorder traversal of binary tree: 1,2,3</p>
<h2>Binary Tree Operations</h2>
<h3>Adding a node</h3>
<ol>
 <li>If the tree is empty, create a new node and set it as the root of the tree.</li>
 <li>Compare the value of the added node with the value of the tree root.</li>
 <li>If the value of the node being added is less than the value of the root, go to the left subtree and recursively call the algorithm for the left subtree.</li>
 <li>If the value of the node being added is greater than the value of the root, go to the right subtree and recursively call the algorithm for the right subtree.</li>
 <li>If the value of the node you are adding is equal to the value of the root, do not take any action (node ​​already exists in the tree).</li>
 <li>Once you have found a suitable place for the node you are adding, create a new node and set it as the left or right descendant of the corresponding node.</li>
</ol>
<h3>Adding a node step-by-step</h3>
<p>Suppose we have a BST tree with root value 8 and we want to add a node with value 7 to it.</p>
<ul>
 <li>The tree is not empty, so we go to step 2.</li>
 <li>We compare the value of the inserted node (7) with the value of the current node (8).</li>
 <li>7 is less than 8, so we move to the left subtree.</li>
 <li>We compare the value of the inserted node (7) with the value of the current node of the left subtree(which is equal to 3).</li>
 <li>7 is greater than 3, so we move to the right subtree of the left subtree.</li>
 <li>Now we compare the value 7 with the value 6 (7>6 so we go to the right subtree)</li>
 <li>The right subtree is empty, so we add a new node with value 7 as a child of node 6.</li>
</ul>
<p align = "center"><img src="https://i.imgur.com/UAFCCS5.png" alt="example1" width="70%" ></p>
<h3>Removing a node</h3>
<ol>
 <li>If the tree is empty, finish the operation.</li>
 <li>Otherwise, find the node to delete. Start at the root and do the following steps:</li>
  <ol type="a">
   <li>If the value of the node to be removed is less than the value of the current node, go to the left one subtrees.</li>
   <li>Otherwise, go to the right subtree.</li>
   <li>If the value of the node to remove is equal to the value of the current node, then we have found the node to deletion.</li>
  </ol>
 <li>Where:</li>
  <ol type="a">
   <li>the node to be removed is a leaf (no children), remove it directly.</li>
   <li>the node to be deleted has one child, replace it with its child.</li>
   <li>the node to be removed has two children, find the inorder successor of this node (the smallest node in right subtree), replace the node values, and then remove the successor inorder.</li>
  </ol>
 <li>Repeat steps 2-3 until we remove the node that we want.</li>
</ol>
<h3>Removing a node step-by-step</h3>
<ul>
 <li>We want to remove the node with value 7. We start with the root whose value is 5.</li>
 <li>7 is greater than 5, so we go to the right subtree.</li>
 <li>Compare the value of 7 with node value 7 -> We found a node to remove.</li>
 <li>Node 7 has two children (6 and 8), so we need to find its inorder successor (i.e. the smallest node in the right subtree).</li>
 <li> The inorder for node 7 is 8, so we replace it values ​​of these nodes and remove node 7.</li>
</ul>
<p align = "center"><img src="https://i.imgur.com/9BCZxTE.png" alt="example2" width="70%" ></p>
<h3>Searching in BST</h3>
<ol>
 <li>If the tree is empty, return nullptr or a value indicating that the item was not found.</li>
 <li>If the value of the element you are looking for is equal to the value of the tree root, return a pointer to the root.</li>
 <li>If the value of the element you are looking for is less than the value
root, search the left subtree recursively, and if it is larger, search the right subtree recursively.</li>
 <li>If the value is not found, return nullptr or a value indicating that the item was not found.</li>
</ol>

<h2>AVL tree</h2>
<p>AVL tree is a self-balancing Binary Search Tree (BST) where the difference between heights of left and right subtrees cannot be more than one for all nodes.</p>
<p align="center"><img src="https://media.geeksforgeeks.org/wp-content/uploads/20221229121830/avl.png" alt="avl_tree"></p>
<p align="center">The above tree is AVL because the differences between the heights of left and right subtrees for every node are less than or equal to 1.</p>
<h2>AVL Tree Operations</h2>
<h3>Adding a node</h3>
<ol>
 <li>Insert a new node into the AVL tree according to the BST tree insertion rules.</li>
 <li>Navigate up the AVL tree from the node that was the last node inserted.</li>
 <li>For each node on the way to the root:</li>
 <ol type="a">
  <li>Update the node height.</li>
  <li>Check whether the subtree rooted at this node is balanced (the difference in height of the right and left subtrees is less than or equal to 1).</li>
  <li>If the subtree is unbalanced, perform an appropriate rotation to balance the tree.</li>
 </ol>
</ol>
<h3>Removing a node</h3>
<ol>
 <li>Delete a node according to the BST deletion rules.</li>
 <li>Navigate up the AVL tree from the node that was the last node deleted.</li>
 <li>For each node on the way to the root:</li>
 <ol type="a">
  <li>Update the node height.</li>
  <li>Check whether the subtree rooted at this node is balanced (the difference in height of the right and left subtrees is less than or equal to 1).</li>
  <li>If the subtree is unbalanced, perform an appropriate rotation to balance the tree.</li>
</ol>
<h3>Balancing a AVL tree</h3>
<ol type="1">
 <li>Check the height difference of the right and left subtrees for each node in the AVL tree.</li>
 <li>For each node whose subtree is unbalanced (the difference in the height of the right and left subtrees is more than 1), perform an appropriate rotation to balance the tree.</li>
</ol>
<p align="center"><img src="https://i.imgur.com/bJJy7fO.png" alt="avl_tree_alg"></p>
<h3>Balancing a AVL tree step-by-step</h3>
<p> In this tree, the difference in height of the left and right subtrees of node 4 is 2 (3 - 1), which means that the tree is unbalanced and we need to use a balancing algorithm.</p>
<ol>
 <li>We check which node is unbalanced. In our case, this is node 4.</li>
 <li>We find the farthest unbalanced node down the tree. In our case, these are nodes 3 and 5.</li>
 <li>We perform appropriate rotation to restore balance. In our case, we perform RR rotation, i.e. we move node 6 to the place of node 4 and node 4 to the place of node 6.</li>
 <li>We update the heights of nodes in the tree.</li>
</ol>
 <p>In the resulting tree, each left and right subtree now has a height difference of at most 1, which means the tree is balanced.</p>
<h2>Difference between BST and AVL tree</h2>
<table align="center">
<thead>
  <tr>
    <th>Binary Search Tree (BST)</th>
    <th>AVL tree</th>
  </tr>
   <tr align="center">
    <td>Simple to implement.</td>
    <td>Complex to implement.</td>
  </tr>
</thead>
<tbody>
  <tr align="center">
    <td>Binary Search Tree doesn't enforce a balance factor for every node</td>
    <td>In AVL Tree, every node follows the balance factor i.e. 0, 1, -1.</td>
  </tr>
  <tr align="center">
    <td>Every Binary Search tree is not an AVL tree.</td>
    <td>Every AVL tree is a Binary Search tree.</td>
  </tr>
  <tr align="center">
    <td >The height or depth of the tree is O(n).</td>
    <td>The height or depth of the tree is O(logn) </td>
  </tr>
  <tr align="center">
    <td>Searching is not efficient when there are a large number of nodes in the Binary Search tree. </td>
    <td>Searching is efficient because searching for the desired node is faster due to the balancing of height. </td>
  </tr>
  <tr align="center">
    <td>The Binary Search tree structure consists of 3 fields left subtree, data, and right subtree. </td>
    <td>AVL tree structure consists of 4 fields left subtree, data, right subtree, and balancing factor.</td>
  </tr>
  <tr align="center">
    <td>not a balanced tree.</td>
    <td>balanced tree.</td>
  </tr>
  <tr align="center">
    <td>In Binary Search tree. Insertion and deletion are easy because no rotations are required. </td>
    <td>In an AVL tree, Insertion and deletion are complex as it requires multiple rotations to balance the tree.</td>
  </tr>
</tbody>
</table>


<h2>References</h2>
<ul>
  <li>Images are taken from <a href="https://www.geeksforgeeks.org/introduction-to-tree-data-structure-and-algorithm-tutorials/">here</a></li>
</ul>
