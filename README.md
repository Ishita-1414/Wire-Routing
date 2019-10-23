# Wire-Routing
# Description of the problem
Given two points on a grid, we have to find the shortest path between them. Additional to this there are some blocked blocks in the grid representated by 0. We cannot pass through that points.
# Application of the problem
Used in designing electrical circuit boards
Used to avoid signal delays in circuit boards
# Our Approach
We have asked user to enter the grid, only 0 and 1 are accepted as input, where 0 represent blocked path and 1 as available path.Then we have asked user to enter the coordinates of the required points. We set that position as 0 and then we called 4 recursive functions: left, right, up and down.These functions increment the value of the block then again call the recursive functions.That's how we get the shortest path between the 2 points.
# Reference

[referred ppt](https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=1&cad=rja&uact=8&ved=2ahUKEwih4PH55LHlAhXOh3AKHcnGASEQFjAAegQIARAB&url=https%3A%2F%2Fwww.coursehero.com%2Ffile%2F31705532%2Flecture6-queueppt%2F&usg=AOvVaw0Lyey5BmtugQSbSNeIV_qs)
