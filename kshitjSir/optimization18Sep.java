package kshitjSir;   
import java.util.HashSet;

class optimization18Sep 
{
    public static int[] isSubArrZero(int[] a)
    {
        int sum = 0;
        int prevSum[] = new int[a.length];
        for(int i=0;i<a.length;i++)
        {
            sum += a[i];
            prevSum[i] = sum;
        }
        HashSet<Integer> hs = new HashSet<>();
        int jindex = -1;
        for(int i =0;i<a.length;i++)
        {
            int b = hs.size();
            hs.add(prevSum[i]);
            if(b == hs.size())
            {
                jindex=i;
                break;
            }
        }
        if(jindex ==-1)
        {
            return new int[] {-1};
        }
        int iindex = 0;
        for(int i=0;i<jindex;i++)
        {
            if(prevSum[i] == prevSum[jindex])
            {
                iindex = i+1;
                break;
            }
        }
        
        int ans[] = new int[jindex-iindex+1];    
        for(int i=iindex;i<=jindex;i++)
        {
            ans[i-iindex] = a[i];
        }
        return ans;
    }
    public static int countSpecialIndex(int a[])
    {
        int b[] = new int[a.length];
        int sumo = 0;
        int sume = 0;
        for(int i=0;i<a.length;i++)
        {
            
            if(i%2 == 0)
            {
                sume += a[i];
                // preSumEven.add(sume);
                b[i] = sume;
            }
            else
            {
                sumo += a[i];
                // preSumOdd.add(sumo);
                b[i] = sumo;
            }
        }
        // for(int i =0;i<b.length;i++)
        // {
        //     System.out.print(b[i]+" ");
        // }
        // System.out.println();
        int c = 0;
        for(int i =0;i<a.length;i++)
        {
            int ein = (i!=0?b[(((i-1)/2)*2)]:0)  + b[(((a.length-1)-1)/2)*2+1]-(i!=0?b[((i-1)/2)*2+1]:0);
            int oin = (i>1?b[i%2==1?i-2:i-1]:0)  + (b[(a.length-1)%2==0?a.length-1:a.length-2]-b[i%2==0?i:i-1]);
            // System.out.println(ein+" "+oin);
            if(ein == oin)
                c++;
            
        }
        return c;

    }
    public static void main(String[] args) 
    {
        int a[] = {1,2,1,2,0};
        System.out.println(countSpecialIndex(a));
        System.out.println();
    }
}