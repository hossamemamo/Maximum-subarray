#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> maxSubArray(vector<int>& nums)
    {
        vector<int> result=findMaxSubArray(nums,0,(nums.size()-1));//we send our parameters (vector,low,high)
        return result;//we only return an integer value = max sum
    }
    vector<int> findMaxCrossSubArray(vector<int>&arr,int low,int mid,int high)
    {
        int sum=0;
        int rightSum=INT_MIN;
        int maxRight;
        for(int j=mid+1; j<=high; j++)
        {
            sum=sum+arr[j];
            if(sum>rightSum)
            {
                rightSum=sum;
                maxRight=j;
            }
        }
        vector<int>rightArr;
        rightArr.push_back(mid);
        rightArr.push_back(maxRight);
        rightArr.push_back(rightSum);

        int leftSum=INT_MIN;
        sum=0;
        int maxLeft;
        for(int i=mid; i>=low; i--)
        {
            sum=sum+arr[i];
            if(sum>leftSum)
            {
                leftSum=sum;
                maxLeft=i;
            }
        }
        vector<int> leftArr;
        leftArr.push_back(maxLeft);
        leftArr.push_back(mid);
        leftArr.push_back(leftSum);


        vector<int> MaxCrossArray;
        MaxCrossArray.push_back(leftArr.at(0));
        MaxCrossArray.push_back(rightArr.at(1));
        MaxCrossArray.push_back(rightArr.at(2)+leftArr.at(2));
        return MaxCrossArray;
    }

    vector<int> findMaxSubArray(vector<int>&arr,int low, int high)
    {
        vector<int> result;
        vector<int> leftArray;
        vector<int> rightArray;
        vector<int> Maxcross;
        if (low==high)
        {
            result.push_back(low);
            result.push_back(high);
            result.push_back(arr.at(low));
            return result;
        }
        else
        {
            int indexMid =(low+high)/ 2;
            leftArray=findMaxSubArray(arr,low,indexMid);  //T(n/2)
            rightArray=findMaxSubArray(arr,indexMid+1,high);//T(n/2)
            Maxcross=findMaxCrossSubArray(arr,low,indexMid,high); //theta(n)
            //total time T(n)=2T(n/2)+theta(n)
            //O(n log n)

        }
        if(leftArray.at(2)>=rightArray.at(2)&&leftArray.at(2)>=Maxcross.at(2))
        {
            return leftArray;
        }
        else if(rightArray.at(2)>=leftArray.at(2)&&rightArray.at(2)>=Maxcross.at(2))
        {
            return rightArray;
        }
        else
        {
            return Maxcross;
        }
    }

    };
int main()
{
    Solution obj;
    std::vector<int>arr= {-2,1,-3,4,-1,2,1,-5,4};
    std::vector<int>result=obj.maxSubArray(arr);
    std::cout<<"max subArray is =  "<<result.at(2)<<"\n";
    std::cout<<"From index = " <<result.at(0)<<"   to    "<<result.at(1);
    return 0;
}
