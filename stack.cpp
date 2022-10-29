 bool ispar(string x)
    {
        // Your code here
        stack<char>s1;
        
        int j = 0; 
        
        while(j<x.length())
        {
            if(s1.empty() && (x[j]='}' || x[j]=']' || x[j]=')'))
            {
                return false;
            }
             
            else if(s1.empty() && (x[j]='{' || x[j]='[' || x[j]='('))
            {
                s1.push(x[j]);
            }
            
            else if(!s1.empty() && ((s1.top()=='[' && x[j]==']') || (s1.top()=='{' && x[j]=='}')  ||  (s1.top()=='(' && x[j]==')')     ))
            {
                    s1.pop();                
            }
            else if(!s1.empty() && ((s1.top()=='{') || (s1.top()=='(') || (s1.top()=='[') ) && (x[j]='{' || x[j]='[' || x[j]='('))
            {
                    s1.push(x[j]);     
            }
            
            else
            {
                return false;
            }
        }
        
        if(s1.empty()) return true;
        return false;
    }
