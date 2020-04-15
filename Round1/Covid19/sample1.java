class Solution 
{ 
    public static double regression(double a, double b, int x, int y, int z){
        double diffY = b-a;
        int diffX = y-x;
        double diffPer = diffY/diffX;
        return a + diffPer*(z-x);
    }
      
    public static int calculateCorona(int N, int O, int k, double m){
        //Left Regression Point
        double leftInfected = N * Math.pow(2, k);
        int left = 6*k;
        double infectionRate = 2;
        for(int i = 6*(k+1); i <= O; i+=6){
          infectionRate -= m;
          if(infectionRate <= 1){ break;}
          left = i;
          leftInfected *= infectionRate;
        }
      
        // Right Regression Point
        infectionRate -= m;
        if(infectionRate < 1)infectionRate = 1;
        int right = left + 6;
        double rightInfected = infectionRate*leftInfected;
      
        int totalInfected = (int)Math.floor(regression(leftInfected, rightInfected, left, right, O));
        return totalInfected;
    }     
    
    public static void main(String args[]) 
    { 
        System.out.println("Hello, World"); 
    } 
} 
