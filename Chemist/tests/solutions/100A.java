import java.util.*;
import java.io.*;
public class Main {
	
	private static ArrayList<Long> decompose(long D){
		ArrayList<Long> ans=new ArrayList<>();
		long prime=2;
		while(D!=1 && prime<=Math.sqrt(D)){
			if(D%prime==0){
				D/=prime;
				ans.add(prime);
			}
			else{
				prime++;
			}
		}
		if(D!=1){
			ans.add(D);
		}
		return ans;
	}
	
	static class Interval implements Comparable<Interval>{
		int L,R;
		long D;
		public Interval(int Lp,int Rp, long Dp){
			L=Lp;
			R=Rp;
			D=Dp;
		}
		public boolean isSame(Interval other){
			int Lo=other.L;
			int Ro=other.R;
			return L==Lo && R==Ro;
		}
		public boolean isPrefix(Interval other){
			int Lo=other.L;
			int Ro=other.R;
			return Ro>R && L==Lo;
		}
		public boolean isSuffix(Interval other){
			int Lo=other.L;
			int Ro=other.R;
			return R==Ro && Lo<=R && Lo>L;
		}
		public boolean intersect(Interval other){
			int Lo=other.L;
			int Ro=other.R;
			return Lo<=R && Ro>=R;
		}
		public int compareTo(Interval interval){
			int res=L-interval.L;
			if(res==0){
				res=R-L-(interval.R-interval.L);
			}
			return res;
		}
		public void cut(Interval other){
			long dValue=getIntersection(D,other.D);
			System.err.println("GCD Cut "+dValue);
			if(isPrefix(other)){
				other.D/=D;
				other.L=R+1;
			}
			else{
				R=other.L-1;
				D/=other.D;
			}
		}
		public Interval divideIntersected(Interval other){
			Interval newInterval=null;
			long intersectionValue=getIntersection(D,other.D);
			System.err.println("GCD "+intersectionValue);
			D/=intersectionValue;
			other.D/=intersectionValue;
			int auxR=R;
			int Lo=other.L;
			R=Lo-1;
			other.L=auxR+1;
			newInterval=new Interval(Lo,auxR,intersectionValue);
			return newInterval;
		}
		public long getIntersection(long a,long b){
			return b==0?a:getIntersection(b,a%b);
		}
		public String toString(){
			return L+"->"+R+":"+D;
		}
	}

	public static void main(String[] args) throws Exception{
		BufferedReader bff=new BufferedReader(new InputStreamReader(System.in));
		PrintWriter wff=new PrintWriter(System.out);
		//10e11
		String[] st=bff.readLine().split(" ");
		int R=Integer.parseInt(st[0]);
		int M=Integer.parseInt(st[1]);
		PriorityQueue<Interval> intervals=new PriorityQueue<>();
		for(int i=0;i<M;i++){
			st=bff.readLine().split(" ");
			int I=Integer.parseInt(st[0])-1;
			int L=Integer.parseInt(st[1])-1;
			long D=Long.parseLong(st[2]);			
			intervals.add(new Interval(I,L,D));		
		}
		
		ArrayList<Interval> order=new ArrayList<>();
		Interval current=null;
		boolean again=false;
		while(!intervals.isEmpty() || again){
			if(again && intervals.isEmpty()){
				intervals.addAll(order);
				again=false;
			}
			if(current==null){
				current=intervals.poll();
			}
			else{
				Interval aux=intervals.poll();
				if(!current.isSame(aux)){
					if(current.isPrefix(aux) || current.isSuffix(aux)){
						System.err.println(current);
						System.err.println(aux);
						System.err.println("Before Cut");
						current.cut(aux);
						intervals.add(aux);
						intervals.add(current);
						System.err.println(current);
						System.err.println(aux);
						System.err.println("After Cut");
						System.err.println();
						current=null;
						again=true;
					}
					else{
						if(current.intersect(aux)){
							System.err.println(current);
							System.err.println(aux);
							System.err.println("Before Intersection Cut");
							Interval newInterval=current.divideIntersected(aux);
							order.add(current);
							intervals.add(aux);
							intervals.add(newInterval);
							System.err.println(current);
							System.err.println(newInterval);
							System.err.println(aux);
							System.err.println("After Intersection Cut");
							System.err.println();
							current=null;
							again=true;
						}
						else{
							order.add(current);
							current=aux;
						}
					}
				}
				else{
					System.err.println("Same");
					System.err.println("Current: "+current);
					System.err.println("Next: "+aux);
					System.err.println();
					if(aux.D!=current.D){
						current.D=Math.max(aux.D, current.D);
					}
				}
			}
		}	
		if(current!=null){
			order.add(current);
		}
		System.err.println(order);
		long[] ans=new long[R];
		for(int i=0;i<order.size();i++){
			Interval in=order.get(i);
			ArrayList<Long> factors=decompose(in.D);
			System.err.println("Interval No: "+(i+1));
			System.err.println(in);
			System.err.println("Factors: "+factors);
			if(factors.size()>0){
				int elements=in.R+1-in.L;
				int distributed=(int)Math.ceil(factors.size()/(double)elements);
				int cont=0;
				long aux=1;
				int idx=in.L;
				for(int j=0;j<factors.size();j++){
					if(cont<distributed){					
						aux*=factors.get(j);
						cont++;
					}
					else{
						j--;
						ans[idx++]=aux;
						cont=0;
						aux=1;
						
					}
				}
				if(cont>0){					
					ans[idx++]=aux;
				}
			}
			else{
				ans[in.L]=1;
			}
		}
		for(int i=0;i<ans.length;i++){
			if(ans[i]!=0){
				wff.print(ans[i]);
			}
			else{
				wff.print(1);
			}
			if(i+1!=ans.length){
				wff.print(" ");
			}
		}
		wff.println();
		wff.flush();
		
	}
}








