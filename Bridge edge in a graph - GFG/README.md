# Bridge edge in a graph
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a&nbsp;Graph of V vertices and E edges and another edge(c -&nbsp;d), the task is to find if the given edge is a Bridge<strong>.</strong>&nbsp;i.e., removing the edge disconnects the graph.</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
<img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700463/Web/Other/5a46c789-a956-4196-a62c-7a1bb9d16db2_1685086697.png" alt="">
<span style="font-size: 18px;"><strong>c</strong> = 1, <strong>d</strong> = 2</span>
<span style="font-size: 18px;"><strong>Output:</strong>
1
<strong>Explanation</strong>:</span>
<span style="font-size: 18px;">From the graph, we can clearly see that
blocking the edge 1-2 will result in 
disconnection of the graph. So, it is 
a Bridge<strong> </strong>and thus the Output 1.</span>

</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
<img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700463/Web/Other/d443aa5e-21e9-47dc-a06e-dd99ea03fbc9_1685086698.png" alt="">
<span style="font-size: 18px;"><strong>c</strong> = 0, <strong>d</strong> = 2</span>
<span style="font-size: 18px;"><strong>Output:</strong>
0
<strong>Explanation</strong>:
</span><img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700463/Web/Other/8be4152b-afea-4c19-802c-ba1647da0cf9_1685086698.png" alt="">
<span style="font-size: 18px;">blocking the edge between nodes 0 and 2
won't affect the connectivity of the graph.
So, it's not a Bridge Edge. All the Bridge
Edges in the graph are marked with a blue
line in the above image.</span>
</pre>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>isBridge()</strong>&nbsp;</span> <span style="font-size: 18px;">which takes number of vertices V<strong>, </strong>the number of edges&nbsp;E<strong>, </strong>an adjacency lsit adj and two integers c and d denoting the edge as input parameters&nbsp;and returns 1 if the given edge c-d is a Bridge<strong>.</strong>&nbsp;Else, it returns 0.</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong>&nbsp;O(V + E).<br><strong>Expected Auxiliary Space:</strong>&nbsp;O(V).</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 </span> <span style="font-size: 18px;">≤</span> <span style="font-size: 18px;"> V,E </span> <span style="font-size: 18px;">≤</span> <span style="font-size: 18px;"> 10<sup>5</sup><br>0 </span> <span style="font-size: 18px;">≤</span> <span style="font-size: 18px;"> c, d </span> <span style="font-size: 18px;">≤</span> <span style="font-size: 18px;"> V-1</span></p></div>