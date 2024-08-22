#include<bits/stdc++.h>                                                                                                                                                                    
                                                                                                                                                                                           
using namespace std;                                                                                                                                                                       

void FIFO()                                                                                                                                                                                
{                                                                                                                                                                                          
        cout << "enter arrival time and bust time:\n";                                                                                                                                     
                                                                                                                                                                                           
        cout <<"enter number of process:";                                                                                                                                                 
        int n;                                                                                                                                                                             
        cin >> n;                                                                                                                                                                          
          vector<vector<int>> prc(n+1,vector<int>(4)); // arrival-0,bust-1,tat-2,wt-3                                                                                                      
        vector<int> bt;                                                                                                                                                                    
        for(int i=0; i<n; i++)                                                                                                                                                             
        {                                                                                                                                                                                  
                int u,v;                                                                                                                                                                   
                cin >> u >> v;                                                                                                                                                             
                prc[i][0]=u;                                                                                                                                                               
                prc[i][1]=v;                                                                                                                                                               
                bt.push_back(v);                                                                                                                                                           
        }                                                                                                                                                                                  
        prc[n][0]=1000;                                                                                                                                                                    
        prc[n][1]=3000;                                                                                                                                                                    
        int c=0,t=0;                                                                                                                                                                       
        while(c!=n)                                                                                                                                                                        
        {                                                                                                                                                                                  
                int slt=n;                                                                                                                                                                 
                for(int j=0; j<n; j++)                                                                                                                                                     
                {                                                                                                                                                                          
                        if(prc[j][0] <= t && prc[j][1]>0)                                                                                                                                  
                        {                                                                                                                                                                  
                                slt=j;                                                                                                                                                     
                                break;                                                                                                                                                     
                        }                                                                                                                                                                  
                }                                                                                                                                                                          
                if(slt!=n)                                                                                                                                                                 
                t=t+prc[slt][1];                                                                                                                                                           
                else                                                                                                                                                                       
                        t++;                                                                                                                                                               
                                                                                                                                                                                           
                if(slt!=n)                                                                                                                                                                 
                {                                                                                                                                                                          
                        prc[slt][2]=t-prc[slt][0];                                                                                                                                         
                        prc[slt][3]=prc[slt][2]- prc[slt][1];                                                                                                                              
                        prc[slt][1]=0;                                                                                                                                                     
                        c++;                                                                                                                                                               
                }                                                                                                                                                                          
        }                                                                                                                                                                                  
                                                                                                                                                                                           
        cout << "AT\tBT\tTAT\tWT\n";                                                                                                                                                       
                                                                                                                                                                                           
        for(int i=0; i<n; i++)                                                                                                                                                             
        {                                                                                                                                                                                  
            cout << prc[i][0] << "\t" << bt[i] << "\t" << prc[i][2] << "\t" << prc[i][3] << endl;                                                                                          
        }                                                                                                                                                                                  
}                                                                                                                                                                                          
                                                                                                                                                                                           
void sjf()                                                                                                                                                                                 
{                                                                                                                                                                                          

                                                                                                                                                                                           
        cout << "enter arrival time and bust time:\n";                                                                                                                                     
                                                                                                                                                                                           
        cout <<"enter number of process:";                                                                                                                                                 
        int n;                                                                                                                                                                             
        cin >> n;                                                                                                                                                                          
         vector<vector<int>> prc(n+1,vector<int>(4)); // arrival-0,bust-1,tat-2,wt-3                                                                                                       
        vector<int> bt;                                                                                                                                                                    
        for(int i=0; i<n; i++)                                                                                                                                                             
        {                                                                                                                                                                                  
                int u,v;                                                                                                                                                                   
                cin >> u >> v;                                                                                                                                                             
                prc[i][0]=u;                                                                                                                                                               
                prc[i][1]=v;                                                                                                                                                               
                bt.push_back(v);                                                                                                                                                           
        }                                                                                                                                                                                  
        prc[n][0]=1000;                                                                                                                                                                    
        prc[n][1]=INT_MAX;                                                                                                                                                                 
        int c=0,slt=n,t=0;                                                                                                                                                                 
                                                                                                                                                                                           
        while(c!=n)                                                                                                                                                                        
        {                                                                                                                                                                                  
            slt=n;                                                                                                                                                                         
            for(int j=0; j<n; j++)                                                                                                                                                         
            {                                                                                                                                                                              
                 if(prc[j][0]<=t && prc[j][1] < prc[slt][1] && prc[j][1] > 0)                                                                                                              
                 {                                                                                                                                                                         
                    slt=j;                                                                                                                                                                 
                 }                                                                                                                                                                         
            }                                                                                                                                                                              
                                                                                                                                                                                           
            if(slt!=n)                                                                                                                                                                     
            {                                                                                                                                                                              
                prc[slt][1]-=1;                                                                                                                                                            
                t++;                                                                                                                                                                       
            }                                                                                                                                                                              
            else                                                                                                                                                                           
            t++;                                                                                                                                                                           
                                                                                                                                                                                           
            if(slt!=n)                                                                                                                                                                     
            {                                                                                                                                                                              
                 if(prc[slt][1]==0)                                                                                                                                                        
                 {                                                                                                                                                                         
                    prc[slt][2]=t-prc[slt][0];                                                                                                                                             
                    prc[slt][3]=prc[slt][2]-bt[slt];                                                                                                                                       
                    c++;                                                                                                                                                                   
                 }                                                                                                                                                                         
            }                                                                                                                                                                              
        }                                                                                                                                                                                  
        cout << "AT\tBT\tTAT\tWT\n";                                                                                                                                                       
                                                                                                                                                                                           
        for(int i=0; i<n; i++)                                                                                                                                                             
        {                                                                                                                                                                                  
            cout << prc[i][0] << "\t" << bt[i] << "\t" << prc[i][2] << "\t" << prc[i][3] << endl;                                                                                          
        }                                                                                                                                                                                  
}                                                                                                                                                                                          
void RR()
{
        cout << "enter arrival time and bust time:\n";                                                                                                                                     
                                                                                                                                                                                           
        cout <<"enter number of process:";                                                                                                                                                 
        int n;                                                                                                                                                                             
        cin >> n;  
        int tq;
        cout <<"Enter time quantum:";
        cin >> tq;                                                                                                                                                                        
         vector<vector<int>> prc(n+1,vector<int>(4)); // arrival-0,bust-1,tat-2,wt-3 
         vector<bool> vis(n,false);                                                                                                      
        vector<int> bt;                                                                                                                                                                    
        for(int i=0; i<n; i++)                                                                                                                                                             
        {                                                                                                                                                                                  
                int u,v;                                                                                                                                                                   
                cin >> u >> v;                                                                                                                                                             
                prc[i][0]=u;                                                                                                                                                               
                prc[i][1]=v;                                                                                                                                                               
                bt.push_back(v);                                                                                                                                                           
        } 
        queue<pair<int,vector<int>>> q;
        q.push({0,prc[0]});
        vis[0]=true;
        int t=0;
        while(!q.empty())
        {
             auto fnt=q.front();
             auto p=fnt.second;
             int ind=fnt.first;
             q.pop();

             if(prc[ind][1] >= tq)
             {
                 prc[ind][1]-=tq;
                 t=t+tq;
             }
             else
             {
                 t=t+prc[ind][1];
                 prc[ind][1]=0;
             }

             for(int i=0; i<n; i++)
             {
                  if(vis[i]==false && prc[i][0]<=t && prc[i][1]>0)
                  {
                     q.push({i,prc[i]});
                     vis[i]=true;
                  }
             }

             if(prc[ind][1]==0)
             {
                 prc[ind][2]=t-prc[ind][0];
                 prc[ind][3]=prc[ind][2]-bt[ind];
             }
             else{
                q.push({ind,p});
             }
        }
     cout << "AT\tBT\tTAT\tWT\n";                                                                                                                                                       
                                                                                                                                                                                           
        for(int i=0; i<n; i++)                                                                                                                                                             
        {                                                                                                                                                                                  
            cout << prc[i][0] << "\t" << bt[i] << "\t" << prc[i][2] << "\t" << prc[i][3] << endl;                                                                                          
        } 
}
void priority()
{
       cout << "enter arrival time and bust time:\n";                                                                                                                                     
                                                                                                                                                                                           
        cout <<"enter number of process:";                                                                                                                                                 
        int n;                                                                                                                                                                             
        cin >> n;                                                                                                                                                                          
        vector<vector<int>> prc(n+1,vector<int>(5)); // arrival-0,bust-1,tat-2,wt-3 ,prio-4                                                                                                     
        vector<int> bt;                                                                                                                                                                    
        for(int i=0; i<n; i++)                                                                                                                                                             
        {                                                                                                                                                                                  
                int u,v,p;                                                                                                                                                                   
                cin >> u >> v >>p;                                                                                                                                                             
                prc[i][0]=u;                                                                                                                                                               
                prc[i][1]=v; 
                prc[i][4]=p;                                                                                                                                                              
                bt.push_back(v);                                                                                                                                                           
        }                                                                                                                                                                                  
        prc[n][0]=1000;                                                                                                                                                                    
        prc[n][1]=INT_MAX;   
        prc[n][4]=INT_MAX;                                                                                                                                                              
        int c=0,slt=n,t=0;                                                                                                                                                                 
                                                                                                                                                                                           
        while(c!=n)                                                                                                                                                                        
        {                                                                                                                                                                                  
            slt=n;                                                                                                                                                                         
            for(int j=0; j<n; j++)                                                                                                                                                         
            {                                                                                                                                                                              
                 if(prc[j][0]<=t && prc[j][4] < prc[slt][4] && prc[j][1] > 0)                                                                                                              
                 {                                                                                                                                                                         
                    slt=j;                                                                                                                                                                 
                 }                                                                                                                                                                         
            }                                                                                                                                                                              
                                                                                                                                                                                           
            if(slt!=n)                                                                                                                                                                     
            {                                                                                                                                                                              
                prc[slt][1]-=1;                                                                                                                                                            
                t++;                                                                                                                                                                       
            }                                                                                                                                                                              
            else                                                                                                                                                                           
            t++;                                                                                                                                                                           
                                                                                                                                                                                           
            if(slt!=n)                                                                                                                                                                     
            {                                                                                                                                                                              
                 if(prc[slt][1]==0)                                                                                                                                                        
                 {                                                                                                                                                                         
                    prc[slt][2]=t-prc[slt][0];                                                                                                                                             
                    prc[slt][3]=prc[slt][2]-bt[slt];                                                                                                                                       
                    c++;                                                                                                                                                                   
                 }                                                                                                                                                                         
            }                                                                                                                                                                              
        }                                                                                                                                                                                  
        cout << "AT\tBT\tTAT\tWT\tPRIO\n";                                                                                                                                                       
                                                                                                                                                                                           
        for(int i=0; i<n; i++)                                                                                                                                                             
        {                                                                                                                                                                                  
            cout << prc[i][0] << "\t" << bt[i] << "\t" << prc[i][2] << "\t" << prc[i][3] << "\t" << prc[i][4] << endl;                                                                                          
        }   
}                                                                                                                                                                                          
int main()                                                                                                                                                                                 
{                                                                                                                                                                                          
    cout << "Enter 1 for FIFO, 2 for SJF, 3 for RR, 4 for priority\n";                                                                                                                     
                                                                                                                                                                                           
    int n;                                                                                                                                                                                 
    cin >> n;                                                                                                                                                                              
    switch(n)                                                                                                                                                                              
    {                                                                                                                                                                                      
        case 1:                                                                                                                                                                            
        FIFO();                                                                                                                                                                            
        break;                                                                                                                                                                             
        case 2:                                                                                                                                                                            
        sjf();                                                                                                                                                                             
        break;                                                                                                                                                                             
        case 3:
        RR();
        break;
        case 4:
        priority();
        break;
        default:                                                                                                                                                                           
        return 0;                                                                                                                                                                          
    }                                                                                                                                                                                      
    return 0;                                                                                                                                                                              
}  