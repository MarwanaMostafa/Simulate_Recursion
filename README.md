# Simulate_Recursion
Simulate recursion through Push (encapsulated call) and Pop(encapsulated call) to a stack and Execute non recursive part


## How to Work :

1-Push an encapsulated call representing the whole subprogram to a stack.

2-Repeat the following: Pop an encapsulated call from the stack. 
  
  2.1-Execute the non-recursive parts.
    
  2.2-If it contains a recursive call (directly or indirectly), do the following:
          
          - Divide the called subprogram into disjoint parts such that each part contains at most one recursive call,
            and each recursive call must be the last statement of one part.
          
          - Encapsulate each called subprogram part into an encapsulated call object.
          
          - Push all parts of the called subprogram to the stack in reverse order.
