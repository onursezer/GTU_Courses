package hw09_121044074_onur_sezer;

/**
 *
 * @author OnurSezer
 * 121044074
 */
public class Polynomial 
{
    private double[] coef;
    private int size;
    
    /**
     * @param arr polinomun katsayilarini alir
     */
    public Polynomial(double[] arr)
    {
        size = arr.length;
        coef = new double[size];
        for (int i = 0; i < size; ++i) 
        {
            coef[i] = arr[i];
        }
    }
    /**
    * @param index set edilecek katsayinin yerini almada kullanilir
    * @param el index'inci katsayi kendisi ile degistirlir
    */
    public void setCoef(int index, double el)
    {
        coef[index] = el;
    }
    /**
     * 
     * @param index get edilecek katsayinin yerini almada kullanilir
     * @return double
     */
    public double getCoef(int index)
    {
        return coef[index]; 
    }
    /**
     * 
     * @return double[] 
     */
    public double[] getCoefArr()
    {
        return coef;
    }
    /**
     * polinomun kaç eleman oldugunu return eder
     * @return integer 
     */
    public int getSize()
    {
        return size;
    }
    /**
     * alinan x degeri ile polinomun sonucu return edilir
     * @param x 
     * @return double
     */
    public double resultPolynomial(double x)
    {
        double sum = 0;
        int i,j;
        for (i = 0, j = getSize(); i < getSize(); i++,j--) 
        {
            sum += getCoef(i) * Math.pow(x, (j-1));
        }
        return sum;
    }
    /**
     * iki tane Polynomial objesini toplar
     * @param obj
     * @return Polynomial
     */
    public Polynomial add(Polynomial obj)
    {
        int i,j;
        if(getSize() > obj.getSize())
        {
            double[] r = new double[getSize()];
            for(i=0;i < getSize()-obj.getSize(); i++)
                r[i] = getCoef(i);
            for (j = 0; j < obj.getSize(); j++,i++) 
                r[i] = getCoef(i) + obj.getCoef(j);
            return new Polynomial(r);       
        }
        else if(getSize() < obj.getSize())
        {
            double[] r = new double[obj.getSize()];
            for(i=0;i < obj.getSize()-getSize(); i++)
                r[i] = obj.getCoef(i);
            for (j = 0; j < getSize(); j++,i++) 
                r[i] = getCoef(j) + obj.getCoef(i);
            return new Polynomial(r);
        }
        else if(getSize() == obj.getSize())
        {
            double[] r = new double[obj.getSize()];
            
            for (i = 0; i < getSize(); i++) 
                r[i] = getCoef(i) + obj.getCoef(i);
            return new Polynomial(r);
            
        }
        return null;
    }
    /**
     * iki tane Polynomial objesini cikarir
     * @param obj
     * @return Polynomial
     */
    public Polynomial sub(Polynomial obj)
    {
       int i,j;
        if(getSize() > obj.getSize())
        {
            double[] r = new double[getSize()];
            for(i=0;i < getSize()-obj.getSize(); i++)
                r[i] = getCoef(i);
            for (j = 0; j < obj.getSize(); j++,i++) 
                r[i] = getCoef(i) - obj.getCoef(j);
            return new Polynomial(r);       
        }
        else if(getSize() < obj.getSize())
        {
            double[] r = new double[obj.getSize()];
            for(i=0;i < obj.getSize()-getSize(); i++)
                r[i] = obj.getCoef(i);
            for (j = 0; j < getSize(); j++,i++) 
                r[i] = getCoef(j) - obj.getCoef(i);
            return new Polynomial(r);
        }
        else if(getSize() == obj.getSize())
        {
            double[] r = new double[obj.getSize()];
            
            for (i = 0; i < getSize(); i++) 
                r[i] = getCoef(i) - obj.getCoef(i);
            return new Polynomial(r);
            
        }
        return null;
        
    }
    /**
     * iki tane Polynomial objesini carpar
     * @param obj
     * @return Polynomial
     */
    public Polynomial mul(Polynomial obj)
    {
       double[] r = new double[getSize() + obj.getSize() - 1];
       for (int i = 0; i < getSize(); i++)
            for (int j = 0; j < obj.getSize(); j++)
                r[i+j] += (coef[i] * obj.coef[j]);
       return new Polynomial(r);
    }

    /**
     * Polynomial objelerini string seklinde ifade etmeyi saglar
     * @return Polynomial
     */
    @Override
    public String toString() 
    {
        String str;
        int i,j;
        str = String.format("%.1fx^%d", getCoef(0),getSize()-1);
        for(i=1,j = getSize()-2; i < getSize(); i++,j--)
        {
            str += " + ";
            if(j == 0)
                str += String.format("%.1f", getCoef(i),j);
            else
                str += String.format("%.1fx^%d", getCoef(i),j);
        }
       return str;
    }
    /**
     * iki tane Polynomial objesinin esitligini kontrol eder
     * @param obj
     * @return boolean
     */
    @Override
    public boolean equals(Object obj) 
    {
        double[] arr1,arr2; 
        Polynomial p;
        p = (Polynomial)obj;
        if(getSize() == p.getSize())
        {
            arr1 = getCoefArr();
            arr2 = p.getCoefArr();
            for (int i = 0; i < getSize(); i++) 
                if(arr1[i] != arr2[i])
                    return false;
        }
        else
            return false;
        return true; 
    }

    public static void main(String[] args) 
    {
        double[] arr = {2,3,4,5,6};
        double[] arr2 = {3,1,4};
        double[] arr3 = {1,1};
        double[] arr4 = {1,-1,1};
        double[] arr5 = {1,-1,1};
        
        Polynomial p = new Polynomial(arr);
        Polynomial p2 = new Polynomial(arr2);
        Polynomial p3 = new Polynomial(arr3);
        Polynomial p4 = new Polynomial(arr4);
        Polynomial p5 = new Polynomial(arr5);
        
        System.out.printf("****** Test of Add ******\n");
        System.out.printf("(%s) +\n(%s)\n= ",p3, p2.toString());
        System.out.println(p3.add(p2).toString());
        System.out.println("");
        System.out.printf("(%s) +\n(%s)\n= ",p, p2.toString());
        System.out.println(p.add(p2).toString()); 
        System.out.println("");
        
        System.out.printf("****** Test of Substract ****** \n");
        System.out.printf("(%s) -\n(%s)\n= ",p, p2.toString());
        System.out.println(p.sub(p2).toString());
        System.out.println("");
        System.out.printf("(%s) -\n(%s)\n= ",p, p2.toString());
        System.out.println(p.add(p2).toString());
        System.out.println("");
        
        System.out.printf("****** Test of Multiplie ****** \n");
        System.out.printf("(%s) *\n(%s)\n= ",p, p2.toString());
        System.out.println(p.mul(p2).toString());
        System.out.println("");
        System.out.printf("(%s) *\n(%s)\n= ",p2, p4.toString());
        System.out.println(p2.mul(p4).toString());
        System.out.println("");
        
        System.out.println("****** Test of Equal ******");
        System.out.printf("(%s) == (%s)\n",p4, p5.toString());
        if(p4.equals(p5))
            System.out.println("=> Equal");
        else
            System.out.println("=> Not Equal");
        System.out.println("");
        System.out.printf("(%s) == (%s)\n",p2, p5.toString());
        if(p2.equals(p5))
            System.out.println("=> Equal");
        else
            System.out.println("=> Not Equal");
        System.out.println("");
        
        System.out.println("****** Test of Evaluate the Polynomial ******");
        double x = 1.0;
        System.out.printf("x : %.1f\n",x);
        System.out.printf("(%s) = %.1f\n",p, p.resultPolynomial(x));
        System.out.println("");
        x = 2.0;
        System.out.printf("x : %.1f\n",x);
        System.out.printf("(%s) = %.1f\n",p3, p3.resultPolynomial(x));
    }

}
