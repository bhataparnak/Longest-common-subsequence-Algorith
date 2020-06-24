
/* Name:- Aparna Krishna Bhat
   University:- University of Texas at Arlington

   Running Instructions:- This file has been coded in c++ using Microsoft Visual Studio Community 2019 Version 16.4.5
   To run the lcs.cpp just add this file in Visual studio and compile and build normally using Fn F5. 
   No compilation error should come. In the terminal pass the desired size of m and n and the values for the same. 
   Program will execute and evaluate by both the methods (Matrix,LSIS)
*/

#include<iostream>
#include<string.h>
#include<windows.h>
#include<vector>
#include<algorithm>
#include <sstream>
#include <set> 
#include <iterator>
#include <map>
#include <chrono>
#include <ctime>

#pragma warning(disable:4996)

using namespace std;




set<int> LongestIncreasingSubsequenceLength(std::vector<int> b)
{

    int n = b.size();
    int* m = new int[b.size()];      // m[i] is the smallest value for an IS with i numbers
    int* seq = new int[b.size() + 1];    // Result sequence
    int* sub = new int[b.size() + 1];    // Predecessor to b[i] in  some IS
    int* mLink = new int[b.size() + 1];
    int* dupRemoved = new int[b.size() + 1];// The value j for the b[j] last used to set m[i]
    int i, j, k, mid, low, high;
    set<int> nonDupSet;



    k = 1;
    m[1] = b[0];
    sub[0] = (-1);
    mLink[1] = 0;
    for (i = 1; i < n; i++)
        if (b[i] >= m[k])
        {
            k++;
            m[k] = b[i];
            sub[i] = mLink[k - 1];
            mLink[k] = i;
        }
        else if (b[i] < m[1])
        {
            m[1] = b[i];
            sub[i] = (-1);
            mLink[1] = i;
        }
        else
        {
            low = 1;
            high = k;

            // printf("start search\n");

            while (low != high - 1)
            {
                //printf("low %d high %d\n", low, high);
                mid = (low + high) / 2;
                if (m[mid] <= b[i])
                    low = mid;
                else
                    high = mid;
            }

            // Check search result

            if (m[low] > b[i] || m[high] <= b[i])
                cout << "error" << endl;
            m[high] = b[i];
            sub[i] = mLink[high - 1];
            mLink[high] = i;
        }

    //cout << "k is " << k;

    // Get result sequence
    i = mLink[k];
    for (j = k - 1; j >= 0; j--)
    {
        seq[j] = b[i];
        i = sub[i];
    }
    for (i = 0; i < k; i++)
    {    
        //cout << seq[i] << " "<< endl;
        nonDupSet.insert(seq[i]);
    }
    


    return nonDupSet;

    /*int i = 0;
    int j = i + 1;

    dupRemoved[0] = seq[0];

    for (int i = 0, j = i + 1; i < k - 1, j < k; i++, j++)
    {
        if (seq[i] != seq[j])
        {
            dupRemoved[i] = seq[i];
            dupRemoved[j] = seq[j];
        }        

    }*/


}
    



int main()
{
    int size_str1 = 0, n = 0, inc_str1 = 0;
    int size_str2 = 0, inc_str2 = 0, m = 0;
    int* arr_first;           //First array
    int* arr_second;         //second array
    int* sortedSecondSequence;
    set<int> sortedSet;
   // map<int, int*> indexMap;
    map<int, std::vector<int>> indexMap;



    std::vector< std::vector<int>> lcs;

    int s, t;
    int store = 0;
    int temp;

    cout << "Please enter the size of the 2 sequences(m n): " << endl;
    cin >> size_str1 >>size_str2 ;

    while (size_str1 > 25000 || size_str2 > 25000)
    {
        cout << "input length cannot exceed 25000. Please re-enter"<< endl;
            size_str1 = 0;
            size_str2 = 0;
            cin >> size_str1 >> size_str2;
    }

    arr_first = new int[size_str1];
    arr_second = new int[size_str2];
    //sortedSecondSequence = new int[size_str2];


    lcs.resize(size_str1 + 1);
    for (int i = 0; i < size_str1 + 1; ++i)
    {
        lcs[i].resize(size_str2 + 1);
    }

    while (n != -1)
    {
        cin >> n;
        arr_first[inc_str1] = n;
        inc_str1++;
    }

  

    while (m != -1)
    {
        cin >> m;
        arr_second[inc_str2] = m;
        //sortedSecondSequence[inc_str2] = m;
        inc_str2++;
    }
    auto start = std::chrono::system_clock::now();
    for (s = 0; s <= size_str1; s++)
    {
        lcs[s][0] = 0;
    }

    for (s = 0; s <= size_str2; s++)
    {
        lcs[0][s] = 0;
    }

    for (s = 1; s <= size_str1; s++)
    {
        for (t = 1; t <= size_str2; t++)
        {
            if (arr_first[s - 1] == arr_second[t - 1])
            {
                lcs[s][t] = 1 + lcs[s - 1][t - 1];
            }

            else
            {
                lcs[s][t] = max(lcs[s - 1][t], lcs[s][t - 1]);
            }
        }
    }

   /* for (s = 0; s <= size_str1; s++)
    {
        for (int t = 0; t <= size_str2; t++)
        {
            cout << lcs[s][t] << " ";
        }
        cout << " " << endl;
    }*/

    //To print LCS by Matrix method

    int index = lcs[size_str1][size_str2];
    int lcsSize = index;
    cout << "length is " << index << endl;

    //charcater array to store LCS

    int* LCS = new int[index + 1];
    LCS[index] = '\0'; // Set the terminating character

    //Storing characters in LCS
    //Start from the bottom right corner character

    int i = size_str1, j = size_str2;
    while (i > 0 && j > 0)
    {
        //if current character in arr_first and arr_second are same, then include this character in LCS[]

        if (arr_first[i - 1] == arr_second[j - 1])
        {
            LCS[index - 1] = arr_first[i - 1]; // Put current character in result
            i--; j--; index--;     // reduce values of i, j and index
        }

        // compare values of lcs[i-1][j] and lcs[i][j-1] and go in direction of greater value.

        else if (lcs[i - 1][j] > lcs[i][j - 1])
            i--;
        else
            j--;
    }

    // Print the LCS
    cout << "LCS is " << endl;
    for (int i = 0; i < lcsSize; i++)
        cout << LCS[i] << " ";
    cout << " " << endl;

    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds1 = end - start;
    std::time_t end_time1 = std::chrono::system_clock::to_time_t(end);

    


    auto startLIS = std::chrono::system_clock::now();
    //Sorting the Second input array in accending order

    /*for (i = 0; i < size_str2; i++)
    {
        for (j = i + 1; j < size_str2; j++)
        {
            if (sortedSecondSequence[i] > sortedSecondSequence[j])
            {
                temp = sortedSecondSequence[i];
                sortedSecondSequence[i] = sortedSecondSequence[j];
                sortedSecondSequence[j] = temp;
            }
        }
    }*/

    //print sorted array elements
    //cout << "Sorted (Ascending Order) Array elements:" << endl;
    for (i = 0; i < size_str2; i++)
    {
        //sortedSet.insert(sortedSecondSequence[i]);
        sortedSet.insert(arr_second[i]);
        //cout << sortedSecondSequence[i] << " ";
        //cout << endl;
    }

    set<int> ::iterator itr;

    for (itr = sortedSet.begin(); itr != sortedSet.end(); ++itr)
    {
        
        std::vector<int> value;
        int index = 0;
        for (int k = size_str2 - 1; k >= 0; k--)
        {
            if (*itr == arr_second[k])
            {
                value.push_back(k);
                index++;
            }
        }
        cout << endl;
        indexMap.insert(pair<int, std::vector<int>>(*itr, value));

    }

   /* map<int, std::vector<int>>::iterator itr1;
    for (itr1 = indexMap.begin(); itr1 != indexMap.end(); ++itr1) {
        cout << itr1->first << " ";
       
        std::vector<int> value = itr1->second;
        
        for (auto i = value.begin(); i != value.end(); ++i)
            cout << *i << " ";
            cout << endl;
    }*/

    std::vector<int> firstSequencesub;

    for (int i = 0 ; i < size_str1; i++)
    {
        std::vector<int> temp = indexMap.find(arr_first[i])->second;
        for (auto k = temp.begin(); k != temp.end(); ++k)
            firstSequencesub.push_back(*k);
        
    }
    /*for (auto k = firstSequencesub.begin(); k != firstSequencesub.end(); ++k)
        cout << *k << " ";*/


    cout << endl;
     set<int> dupRemovedSet = LongestIncreasingSubsequenceLength(firstSequencesub);
     vector<int> lis;
     set<int> ::iterator itr2;

     for (itr2 = dupRemovedSet.begin(); itr2 != dupRemovedSet.end(); ++itr2)
     {
         //cout << *itr2 << " ";
         lis.push_back(arr_second[*itr2]);
     }

     auto endLIS = std::chrono::system_clock::now();
     std::chrono::duration<double> elapsed_seconds2 = endLIS - startLIS;
     std::time_t end_time2 = std::chrono::system_clock::to_time_t(endLIS);

     

     int* lcs2 = new int[lis.size()];
     std::copy(lis.begin(), lis.end(), lcs2);

     cout << endl;


     //for (auto k = lis.begin(); k != lis.end(); ++k)
        // cout << *k << " ";
     cout << lcsSize << endl;
     for (int i = 0; i < lcsSize; i++)
     {
         if(LCS[i]==lcs2[i])
             cout << LCS[i] << " "<<endl;
     }
     cout << -1 << endl;
     std::cout << "finished matrix computation at " << std::ctime(&end_time1)
         << "LCS comp time with cost matrix is : " << elapsed_seconds1.count() << "s\n";
     std::cout << "finished LIS computation at " << std::ctime(&end_time2)
         << "elapsed time: " << elapsed_seconds2.count() << "s\n";
         

    return 0;

}



