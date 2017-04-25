#include<bits/stdc++.h>
#define n 4
using namespace std;
 
// Returns length of the longest path beginning with mat[i][j].
// This function mainly uses lookup table dp[n][n]
int findLongestFromACell(int i, int j, int mat[n][n], int dp[n][n])
{
    // Base case
    if (i<0 || i>=n || j<0 || j>=n)
        return 0;
 
    // If this subproblem is already solved
    if (dp[i][j] != -1)
        return dp[i][j];
 
    // Since all numbers are unique and in range from 1 to n*n,
    // there is atmost one possible direction from any cell
    if (j<n-1 && ((mat[i][j] +1) == mat[i][j+1]))
       return dp[i][j] = 1 + findLongestFromACell(i,j+1,mat,dp);
 
    if (j>0 && (mat[i][j] +1 == mat[i][j-1]))
       return dp[i][j] = 1 + findLongestFromACell(i,j-1,mat,dp);
 
    if (i>0 && (mat[i][j] +1 == mat[i-1][j]))
       return dp[i][j] = 1 + findLongestFromACell(i-1,j,mat,dp);
 
    if (i<n-1 && (mat[i][j] +1 == mat[i+1][j]))
       return dp[i][j] = 1 + findLongestFromACell(i+1,j,mat,dp);
 
    // If none of the adjacent fours is one greater
    return dp[i][j] = 1;
}
 
// Returns length of the longest path beginning with any cell
int finLongestOverAll(int mat[n][n])
{
    int result = 1;  // Initialize result
 
    // Create a lookup table and fill all entries in it as -1
    int dp[n][n];
    memset(dp, -1, sizeof dp);
 
    // Compute longest path beginning from all cells
    for (int i=0; i<n; i++)
    {
      for (int j=0; j<n; j++)
       {
          if (dp[i][j] == -1)
             findLongestFromACell(i, j, mat, dp);
 
          //  Update result if needed
          result = max(result, dp[i][j]);
       }
     }
 
     return result;
}
int p=-999;



void rotate(int mat[n][n])
{
	for (int i = 0; i < n/2; ++i)
	{
		for (int j = i; j < n-i-1; ++j)
		{
			 int temp = mat[i][j];
			 mat[i][j] = mat[j][n-i-1];
			 mat[j][n-i-1] = mat[n-i-1][n-j-1];
			 mat[n-i-1][n-j-1] = mat[n-j-1][i];
			 mat[n-j-1][i] = temp;
		}
	}

}
int angle(int h,int m)
{
	if (h<0 || h>12 || m >60 || m<0 )
	{
		return -1;
		/* code */
	}
	if (h==12)
	{
		h=0;
		/* code */
	}
	if (m==60)
	{
		m=0;
		/* code */
	}
	int am = 6*m;
	int ah = 0.5*(60*h + m);
	int angle = abs(am -ah);
	return min(360-angle,angle);
}
class node
 {
 public:
 	int data;
 	node* left;
 	node* right;
 	
 };
 class tree
  {
  public:
  	// node *root; 
  	node* newnode(int k)
  	{
  		node* curr = new node;
 		curr->data = k;
 		curr->left=NULL;
 		curr->right=NULL;
 		return curr;
 	}
  	node* insert(int k,node* curr)
  	{
        if (curr==NULL)
        {
        	return(newnode(k));
        }
        else{
        		if(curr->data > k)
       			 {
               		curr->left = insert(k,curr->left);	
       			 }
       		 else
        		{
       	 		 curr->right = insert(k,curr->right);
       			 }
        }
        return curr;	
  	} 
  	
  };
  int longestsum(node* root)
{
	if (root==NULL)
	{
		return 0;
		/* code */
	}
	int l = longestsum(root->left);
	int r = longestsum(root->right);

	int maxi = max(max(l,r)+root->data,root->data);
	int max1 = max(maxi,l+r+root->data);
	p = max(p,max1);
	return maxi;
}
void print(node* curr)
{

	if (curr!=NULL)
	{
		cout<<curr->data<<endl;
		print(curr->left);
		print(curr->right); 
		/* code */
	}
}

int mindep(node* root)
{
	if (root==NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right==NULL)
	{
		return 1;
		/* code */
	}
	if (root->left==NULL)
	{
		return 1 + mindep(root->right);
		/* code */
	}
	if(root->right==NULL)
	{
		return 1 + mindep(root->left);
	}
	return min(mindep(root->right),mindep(root->left)) + 1;
}
int ht(node* root)
{
	if(root!=NULL)
	{
		return 1 + max(ht(root->left),ht(root->right));
	}
	return 0;	
}
int diameter(node* root)
{
	if (root==NULL)
	{
		return 0;
		/* code */
	}
	int l = ht(root->left);
	int r = ht(root->right);
	int dia = max(l+r+1,max(diameter(root->left),diameter(root->right)));
	return dia;
}
int full(node* root)
{
	if (root==NULL)
	{
		return 1;
	}
	if (root->left == NULL && root->right==NULL)
	{
		return 1;
		/* code */
	}
	if (root->left != NULL && root->right!=NULL)
	{
		if (full(root->left)&&full(root->right))
		{
			return 1;
			/* code */
		}
		/* code */
	}
	return 0;
}
int mirror(node* root)
{
	if (root==NULL)
	{
		return -1; 
		/* code */
	}
	else{
		  mirror(root->left);
		  mirror(root->right);
		  node* temp;
		  temp = root->left;
		  root->left = root->right;
		  root->right = temp;
	}
}	    
// Driver program
int main()
{
   // int  mat[n][n] = 
   // {{1, 2, 3, 4},
   //  {5, 6, 7, 8},
   //  {9, 10, 11, 12},
   //  {13, 14, 15, 16}
   // };
   // cout << "Length of the longest path is "
   //      << finLongestOverAll(mat);
   // rotate(mat);
   // for (int i = 0; i < n; ++i)
   //      {
   //      	for (int j = 0; j < n; ++j)
   //      	{
   //      		cout<<mat[i][j]<<" ";
   //      	}
   //      	cout<<endl;
   // //      }     
   // cout<<angle(0,15)<<endl;
   node* root = NULL;
   tree a;
   root = a.insert(2,root);
   a.insert(3,root);
   a.insert(1,root);
    a.insert(4,root);
   a.insert(5,root);
    print(root);
    // cout<<mindep(root)<<endl;
    // longestsum(root);
    // cout<<p<<endl;
    // cout<<full(root)<<endl;
    // cout<<diameter(root)<<endl;
    mirror(root);
    print(root);  
   return 0;
}