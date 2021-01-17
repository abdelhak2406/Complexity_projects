import java.math.BigInteger;
import java.util.Scanner;


public class RecSum{

	public static BigInteger somme( BigInteger n){
		if (n.intValue()<=1) {
			return BigInteger.ONE;
		} else {
			return somme(n.subtract(BigInteger.ONE)).add(n);
		}
	}

	public static void main(String[] args) {
		long lStartTime,timeMilisec;
		BigInteger n;
		BigInteger s;
		Scanner lire = new Scanner(System.in);
		System.out.println("Entrez un nombre : ");
		n= BigInteger.valueOf(Integer.parseInt(lire.nextLine()));
		lire.close();
		lStartTime = System.nanoTime();
		s = somme(n);
		lStartTime = System.nanoTime() - lStartTime;
		timeMilisec =  TimeUnit.NANOSECONDS.toMillis(lStartTime);
		System.out.println("La somme des "+n+" premiers entiers naturels est: " +s);
		System.out.println("******** Temps d'execution en millisecondes : "+ timeMilisec);
	}
}
