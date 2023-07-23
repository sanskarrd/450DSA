# Minimum swap required to convert binary tree to binary search tree
## Hard
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array&nbsp;<strong>A[]</strong>&nbsp;which represents&nbsp;a&nbsp;Complete Binary Tree i.e, if index <strong>i</strong> is the parent, index <strong>2*i + 1</strong> is the left child and index <strong>2*i + 2</strong> is the right child.<br>
The task is to find the minimum number of swaps required to convert it into a Binary Search Tree.&nbsp;</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>A[] = { 5, 6, 7, 8, 9, 10, 11 }
<strong>Output: </strong>3
<strong>Explanation:</strong> 
Binary tree of the given array:
<img alt="" src="https://media.geeksforgeeks.org/img-practice/btree-1646375730.png" style="height:175px; width:300px">
Swap 1: Swap node 8 with node 5.
Swap 2: Swap node 9 with node 10.
Swap 3: Swap node 10 with node 7.
<img alt="" src="https://media.geeksforgeeks.org/img-practice/btreex-1646375822.png" style="height:187px; width:300px">
So, minimum 3 swaps are required.</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: 
</strong>A[] = {1, 2, 3}
<strong>Output: </strong>1
</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>minSwaps</strong><strong>()</strong>&nbsp;which takes an array&nbsp;<strong>A[]&nbsp;</strong>and returns an integer as output.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(NlogN)<br>
<strong>Expected Auxiliary Space:</strong> O(N)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N&nbsp;&lt;= 10<sup>5</sup></span></p>
</div>