import java.util.Scanner;
public class Lru 
{
	public static void main(String args[])
	{
	Scanner s=new Scanner(System.in);
	int ch;
	Lru l=new Lru();
	System.out.println("enter the number of pages\n");
	int p=s.nextInt();
	System.out.println("enter the frame size\n");
	int f=s.nextInt();
	int frame[]=new int[f];
	int pages[]=new int[p];
	System.out.println("enter the page referencce string\n");
	for(int i=0;i<p;i++)
	pages[i]=s.nextInt();
	System.out.println("1.FIFO 2.LRU\n");
	ch=s.nextInt();
	switch(ch)
	{
	case 1:System.out.println("FIFO");
	l.fifo(frame,pages,f,p);
	break;
	case 2:System.out.println("LRU");
	l.lru(frame,pages,p,f);
	break;
	
	}
	
	}
	static void fifo(int frame[],int pages[],int f,int p)
	{
	int pagehit=0,page,fault=0,num=0;
	boolean flag=true;
	for(int i=0;i<f;i++)
	{
	frame[i]=-1;
	}
	for(int i=0;i<p;i++)
	{
	flag=true;
	page=pages[i];
	for(int j=0;j<f;j++)
	{
	if(frame[j]==page)
	{
	flag=false;
	pagehit++;
	break;
	}
	}
	if(num==f)
	num=0;
	if(flag)
	{
	frame[num]=page;
	num++;
	}
	System.out.println("frame:");
	for(int k=0;k<f;k++)
	System.out.println(frame[k]+" ");
	
	}
	fault=p-pagehit;
	System.out.println("pagehit: "+pagehit);
	System.out.println("pagefault: "+fault);
	}
	
	
	static void lru(int frame[],int pages[],int p,int f)
	{
	int pagehit=0,page,fault=0,recent=0;
	boolean flag=false;
	int counter[]=new int[f];
	for(int i=0;i<f;i++)
	{
	frame[i]=-1;
	}
	
	for(int i=0;i<f;i++)
	{
	counter[i]=0;
	}
	for(int i=0;i<p;i++)
	{
	flag=true;
	page=pages[i];
	for(int j=0;j<f;j++)
	{
	if(frame[j]==page)
	{
	flag=false;
	counter[j]=++recent;
	pagehit++;
	break;
	
	}
	
	}
	if(flag)
	{
	int position=min(counter,f);
	
	frame[position]=page;
	counter[position]=++recent;
	fault++;
	}
	System.out.println("frame:");
	for(int k=0;k<f;k++)
	System.out.println(frame[k]+" ");
	
	
	}
	System.out.println("pagehit: "+pagehit);
	System.out.println("pagefault: "+fault);
	
	}
	static int  min(int counter[],int f)
	{
	int i,min=counter[0],position=0;
	for(i=1;i<f;i++)
	{
	if(counter[i]<min)
	{
	min=counter[i];
	position=i;
	}
	}
	return position;
	}
	
}
