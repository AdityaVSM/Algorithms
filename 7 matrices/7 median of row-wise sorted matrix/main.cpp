#include<bits/stdc++.h>
using namespace std;
/*
Given an matrix with following consitions:
* odd sized matrix
* no repetitive elements
* sorted row wise

median = middle of sorted list of numbers

(1) Naive = put all elements in array => sort => return middle ele
*/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;

int matMed(int mat[][MAX], int r ,int c){   //O(r*log(max-min)*logc)
	int min = mat[0][0], max = mat[0][c-1];
    //Find min and max ele (they are present in first and last column respectively)
	for (int i=1; i<r; i++){    //O(r)
		if (mat[i][0] < min)
			min = mat[i][0];

		if (mat[i][c-1] > max)
			max = mat[i][c-1];
	}

	int medPos = (r * c + 1) / 2;
	while (min < max){          //O(log(max-min))
		int mid = (min + max) / 2;
		int midPos = 0;

        //sum of indices of all elements which are just greater than mid in every row
		for (int i = 0; i < r; ++i) //O(r)
			midPos += upper_bound(mat[i], mat[i]+c, mid) - mat[i];  //O(logc)
		if (midPos < medPos)
			min = mid + 1;
		else
			max = mid;
	}
	return min;
}

int main(){
	int r = 3, c = 5;
	int m[][MAX]= { 
        {5,10,20,30,40}, 
        {1,2,3,4,6}, 
        {11,13,15,17,19} 
    };
	cout << "Median is " << matMed(m, r, c) << endl;
	return 0;
}
