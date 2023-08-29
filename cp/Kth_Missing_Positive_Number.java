package cp;
class Kth_Missing_Positive_Number
{
    public static int lessThanNo(int [] arr, int a,int k)
    {
        int st=0;
        int en=arr.length-1,c=0;
        while(st<=en)
        {
            int mid=(st+en)/2;
            if(arr[mid]<=k)
            {
                c=mid+1;
                st=mid+1;
            }
            else
                en=mid-1;
        }
        return c-a;
    }
    public static void main(String[] args) {
        int arr[] = {1,2,4,4,5,7,8,10,14,16};
        System.out.println(lessThanNo(arr, 6, 14));
    }
}