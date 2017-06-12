/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw10_121044074_onur_sezer;

import static java.lang.System.exit;
import java.util.ArrayList;

/**
 *
 * @author Onur Sezer
 * 
 * Matematiksel ifadenin sonucunun bulunmasında kullanildi
 * 
 */
public class Expression {
    private  ArrayList<Base> arr;
    public int resultEvaluate; 
    
    /**
     * Base tipinde array list alir ve arr fieldini ilklendirir
     * @param _arr 
     */
    public Expression(ArrayList<Base>  _arr) 
    {    
        arr = _arr;   
        resultEvaluate = 0;
    }

    /**
     * array olarak gelen matematiksel ifadenin hangi classin objesi oldugunubulur 
     * islem onceliklerini dikkate alir
     * her bir basamagin sonucunu ekrana basar
     * 
     */
    public void evaluate()
    {    
        int lpar = 0, rpar = 0;
        int ct = 0;
        System.out.println("Input :");
        System.out.println(toString());
        System.out.println("Output :");
        
        for (int j=0; j < arr.size(); j++) // parentaz kontrolu
        {
            if(arr.get(j) instanceof  Paranthesis)
            {
                Paranthesis p = (Paranthesis) arr.get(j);
                if(p.getPar().equals("("))                    
                    ++lpar;
                else if(p.getPar().equals(")"))
                    ++rpar;
            }            
        }
        //System.out.println("lpar : "+lpar);
        //System.out.println("rpar : "+rpar);
        if(lpar != rpar)
        {
            System.out.println("Parantezler eksik");
            exit(0);    // exception yerleştir      
        }
        int lst = -1, rst = 0;
        for(int i = 0; i < lpar; i++) // parentez cifti kadar doner
        {
            for (int j=0; j < arr.size(); j++)  // sol ve sag parentezin gectigi indexi bulur
            {
                if(arr.get(j) instanceof  Paranthesis)
                {
                    Paranthesis p = (Paranthesis) arr.get(j);
                    if(p.getPar().equals("("))
                    {
                       lst = j;
                    }
                    if(p.getPar().equals(")"))
                    {
                        if(lst == -1)
                        {
                            System.out.println("Ilk sag parentez girilmis");
                            exit(0);
                        }
                        rst = j;
                        break;
                    }
                }
            }
            int[] index = new int[100];
            int s_index = 0;
            for(int k=lst; k <= rst; k++) // parentezin icinde, carpma ya da bolme varsa indexlerini bulur 
            {
                if(arr.get(k) instanceof  Operator)
                {
                    Operator o = (Operator) arr.get(k);
                    if(o.getOperator().equals("*"))
                    {
                        //System.out.println("carpma operatoru index :"+k);
                        index[s_index] = k;
                        s_index++;
                    }
                    else if(o.getOperator().equals("/"))
                    {
                        //System.out.println("bolme operatoru index :"+k);
                        index[s_index] = k;
                        s_index++;
                    }
                }
            }
            if(s_index > 0) // carpma, bolme operatorunun islemlerini yapar
            {
                for (int j = 0; j < s_index; j++) 
                {
                    if(!(arr.get(index[j] - 1) instanceof  Operand)) // operatorun sol tarinda operand yoksa hata verir
                    {
                        //System.out.println("index[j] : "+index[j]);
                        System.out.println("operatorun sol tarafinda operand yok");
                        exit(0);
                    }
                    if(!(arr.get(index[j] + 1) instanceof  Operand)) // operatorun sag tarinda operand yoksa hata verir
                    {
                        //System.out.println("index[j] : "+index[j]);
                        System.out.println("operatorun sag tarafinda operand yok");
                        exit(0);
                    }
                    Operator o = (Operator) arr.get(index[j]);
                    if(o.getOperator().equals("*"))
                    {
                        Operand operand = (Operand) arr.get(index[j] - 1);
                        int num1 = Integer.parseInt(operand.getOperand());
                        Operand operand2 = (Operand) arr.get(index[j] + 1);
                        int num2 = Integer.parseInt(operand2.getOperand());
                        //System.out.println("num1 : "+num1);
                        //System.out.println("num2 : "+num2);
                        int result = num1 * num2;
                        String str = Integer.toString(result); 
                        Operand change = new Operand(str); // carpmanın sonucu operand objesi olarak olarak arrarye eklenir
                        arr.set(index[j] - 1, change);
                        arr.remove(index[j]);
                        arr.remove(index[j]);
                        ct++;
                        System.out.printf("%d: %s\n",ct,toString());
                    }
                    else if(o.getOperator().equals("/"))
                    {
                        Operand operand = (Operand) arr.get(index[j] - 1);
                        int num1 = Integer.parseInt(operand.getOperand());
                        Operand operand2 = (Operand) arr.get(index[j] + 1);
                        int num2 = Integer.parseInt(operand2.getOperand());
                        //System.out.println("num1 : "+num1);
                        //System.out.println("num2 : "+num2);
                        int result = num1 / num2;
                        String str = Integer.toString(result); 
                        Operand change = new Operand(str); // bolmenin sonucu operand objesi olarak olarak arrarye eklenir
                        arr.set(index[j] - 1, change);
                        arr.remove(index[j]);
                        arr.remove(index[j]);
                        ct++;
                        System.out.printf("%d: %s\n",ct,toString());
                    }
                    // carpma ya da bolme yaptıktan sonra array degistigi icin tekrar parentezlerin yerleri bulunur
                    for (int k=0; k < arr.size(); k++)  // sol ve sag parentezin gectigi indexi bulur
                    {
                        if(arr.get(k) instanceof  Paranthesis)
                        {
                            Paranthesis p = (Paranthesis) arr.get(k);
                            if(p.getPar().equals("("))
                            {
                               lst = k;
                            }
                            if(p.getPar().equals(")"))
                            {
                                rst = k;
                                break;
                            }
                        }
                    }
                    int newIndex = j + 1;
                    // degisen arrayde, geriye kalan carpma ya da bolmenin indexleri bulunur
                    for(int k=lst; k <= rst; k++) // parentezin icinde, carpma ya da bolme varsa indexlerini bulur 
                    {
                        if(arr.get(k) instanceof  Operator)
                        {
                            Operator op = (Operator) arr.get(k);
                            if(op.getOperator().equals("*"))
                            {
                                //System.out.println("carpma operatoru index :"+k);
                                index[newIndex] = k;
                                newIndex++;
                            }
                            else if(op.getOperator().equals("/"))
                            {
                                //System.out.println("bolme operatoru index :"+k);
                                index[newIndex] = k;
                                newIndex++;
                            }
                        }
                    } 
                }
            }
            int t_index = 0;
            int[] index2 = new int[100];
            for(int k=lst; k <= rst; k++) // parentezin icinde, toplama ya da cıkarma varsa indexlerini bulur 
            {
                if(arr.get(k) instanceof  Operator)
                {
                    Operator o = (Operator) arr.get(k);
                    if(o.getOperator().equals("+"))
                    {
                        //System.out.println("toplama operatoru index :"+k);
                        index2[t_index] = k;
                        t_index++;
                    }
                    else if(o.getOperator().equals("-"))
                    {
                        //System.out.println("cıkarma operatoru index :"+k);
                        index2[t_index] = k;
                        t_index++;
                    }
                }
            }
            if(t_index > 0) // toplama, cıkarma operatorunun islemlerini yapar
            {
                for (int j = 0; j < t_index; j++) 
                {

                    if(!(arr.get(index2[j] - 1) instanceof  Operand)) // operatorun sol tarinda operand yoksa hata verir
                    {
                        //System.out.println("index2[j] : "+index2[j]);
                        System.out.println("operatorun sol tarafinda operand yok");
                        exit(0);
                    }
                    if(!(arr.get(index2[j] + 1) instanceof  Operand)) // operatorun sag tarinda operand yoksa hata verir
                    {
                        //System.out.println("index2[j] : "+index2[j]);
                        System.out.println("operatorun sag tarafinda operand yok");
                        exit(0);
                    }
                    
                    Operator o = (Operator) arr.get(index2[j]);
                    if(o.getOperator().equals("+"))
                    {
                        Operand operand = (Operand) arr.get(index2[j] - 1);
                        int num1 = Integer.parseInt(operand.getOperand());
                        Operand operand2 = (Operand) arr.get(index2[j] + 1);
                        int num2 = Integer.parseInt(operand2.getOperand());
                        //System.out.println("num1 : "+num1);
                        //System.out.println("num2 : "+num2);
                        int result = num1 + num2;
                        String str = Integer.toString(result); 
                        Operand change = new Operand(str); // carpmanın sonucu operand objesi olarak olarak arrarye eklenir
                        arr.set(index2[j] - 1, change);
                        arr.remove(index2[j]);
                        arr.remove(index2[j]);
                        ct++;
                        System.out.printf("%d: %s\n",ct,toString());
                    }
                    else if(o.getOperator().equals("-"))
                    {
                        Operand operand = (Operand) arr.get(index2[j] - 1);
                        int num1 = Integer.parseInt(operand.getOperand());
                        Operand operand2 = (Operand) arr.get(index2[j] + 1);
                        int num2 = Integer.parseInt(operand2.getOperand());
                        //System.out.println("num1 : "+num1);
                        //System.out.println("num2 : "+num2);
                        int result = num1 - num2;
                        String str = Integer.toString(result); 
                        Operand change = new Operand(str); // bolmenin sonucu operand objesi olarak olarak arrarye eklenir
                        arr.set(index2[j] - 1, change);
                        arr.remove(index2[j]);
                        arr.remove(index2[j]);
                        ct++;
                        System.out.printf("%d: %s\n",ct,toString());
                    }
                    
                    // toplama ya da cikarma yaptiktan sonra array degistigi icin tekrar parentezlerin yerleri bulunur
                    for (int k=0; k < arr.size(); k++)  // sol ve sag parentezin gectigi indexi bulur
                    {
                        if(arr.get(k) instanceof  Paranthesis)
                        {
                            Paranthesis p = (Paranthesis) arr.get(k);
                            if(p.getPar().equals("("))
                            {
                               lst = k;
                            }
                            if(p.getPar().equals(")"))
                            {
                                rst = k;
                                break;
                            }
                        }
                    }
                    int newIndex = j + 1;
                    // degisen arrayde, geriye kalan toplama ya da cıkarma indexleri bulunur
                    for(int k=lst; k <= rst; k++) // parentezin icinde, toplama ya da cıkarma varsa indexlerini bulur 
                    {
                        if(arr.get(k) instanceof  Operator)
                        {
                            Operator op = (Operator) arr.get(k);
                            if(op.getOperator().equals("+"))
                            {
                                index2[newIndex] = k;
                                newIndex++;
                            }
                            else if(op.getOperator().equals("-"))
                            {
                                index2[newIndex] = k;
                                newIndex++;
                            }
                        }
                    } 
                }
            }
            for (int j=0; j < arr.size(); j++)  // parentez islemi bittikten sonra parentezler kaldirilir
            {
                if(arr.get(j) instanceof  Paranthesis)
                {
                    Paranthesis p = (Paranthesis) arr.get(j);
                    if(p.getPar().equals("("))
                    {
                       lst = j;
                    }
                    if(p.getPar().equals(")"))
                    {
                        rst = j;
                        break;
                    }
                }
            }
            arr.remove(lst);    // sol ve sag parentez islem yapıldıktan sonra silinir
            arr.remove(lst + 1);                        
        }
        
        // parentez işlemi yapıldıktan sonra geriye kalan islemler yapılır
        //System.out.println("parentezden sonra");
        int[] index = new int[100];
        int s_index = 0;
        for(int k=0; k < arr.size(); k++) // carpma ya da bolme varsa indexlerini bulur 
        {
            if(arr.get(k) instanceof  Operator)
            {
                Operator o = (Operator) arr.get(k);
                if(o.getOperator().equals("*"))
                {
                    index[s_index] = k;
                    s_index++;
                }
                else if(o.getOperator().equals("/"))
                {
                    index[s_index] = k;
                    s_index++;
                }
            }
        }
        if(s_index > 0) // carpma, bolme operatorunun islemlerini yapar
        {
            for (int j = 0; j < s_index; j++) 
            {
                if(!(arr.get(index[j] - 1) instanceof  Operand)) // operatorun sol tarinda operand yoksa hata verir
                {
                    System.out.println("operatorun sol tarafinda operand yok");
                    exit(0);
                }
                if(!(arr.get(index[j] + 1) instanceof  Operand)) // operatorun sag tarinda operand yoksa hata verir
                {
                    System.out.println("operatorun sag tarafinda operand yok");
                    exit(0);
                }

                Operator o = (Operator) arr.get(index[j]);
                if(o.getOperator().equals("*"))
                {
                    Operand operand = (Operand) arr.get(index[j] - 1);
                    int num1 = Integer.parseInt(operand.getOperand());
                    Operand operand2 = (Operand) arr.get(index[j] + 1);
                    int num2 = Integer.parseInt(operand2.getOperand());
                    int result = num1 * num2;
                    String str = Integer.toString(result); 
                    Operand change = new Operand(str); // carpmanın sonucu operand objesi olarak olarak arrarye eklenir
                    arr.set(index[j] - 1, change);
                    arr.remove(index[j]);
                    arr.remove(index[j]);
                    ct++;
                    System.out.printf("%d: %s\n",ct,toString());
                }
                else if(o.getOperator().equals("/"))
                {
                    Operand operand = (Operand) arr.get(index[j] - 1);
                    int num1 = Integer.parseInt(operand.getOperand());
                    Operand operand2 = (Operand) arr.get(index[j] + 1);
                    int num2 = Integer.parseInt(operand2.getOperand());
                    int result = num1 / num2;
                    String str = Integer.toString(result); 
                    Operand change = new Operand(str); // bolmenin sonucu operand objesi olarak olarak arrarye eklenir
                    arr.set(index[j] - 1, change);
                    arr.remove(index[j]);
                    arr.remove(index[j]);
                    ct++;
                    System.out.printf("%d: %s\n",ct,toString());
                }

                int newIndex = j + 1;
                // degisen arrayde, geriye kalan carpma ya da bolmenin indexleri bulunur
                for(int k=0; k < arr.size(); k++) //  carpma ya da bolme varsa indexlerini bulur 
                {
                    if(arr.get(k) instanceof  Operator)
                    {
                        Operator op = (Operator) arr.get(k);
                        if(op.getOperator().equals("*"))
                        {
                            index[newIndex] = k;
                            newIndex++;
                        }
                        else if(op.getOperator().equals("/"))
                        {
                            index[newIndex] = k;
                            newIndex++;
                        }
                    }
                } 
            }
        }
        int t_index = 0;
        int[] index2 = new int[100];
        for(int k=0; k < arr.size(); k++) // toplama ya da cıkarma varsa indexlerini bulur 
        {
            if(arr.get(k) instanceof  Operator)
            {
                Operator o = (Operator) arr.get(k);
                if(o.getOperator().equals("+"))
                {
                    index2[t_index] = k;
                    t_index++;
                }
                else if(o.getOperator().equals("-"))
                {
                    index2[t_index] = k;
                    t_index++;
                }
            }
        }
        if(t_index > 0) // toplama, cıkarma operatorunun islemlerini yapar
        {
            for (int j = 0; j < t_index; j++) 
            {

                if(!(arr.get(index2[j] - 1) instanceof  Operand)) // operatorun sol tarinda operand yoksa hata verir
                {
                    System.out.println("operatorun sol tarafinda operand yok");
                    exit(0);
                }
                if(!(arr.get(index2[j] + 1) instanceof  Operand)) // operatorun sag tarinda operand yoksa hata verir
                {
                    System.out.println("operatorun sag tarafinda operand yok");
                    exit(0);
                }

                Operator o = (Operator) arr.get(index2[j]);
                if(o.getOperator().equals("+"))
                {
                    Operand operand = (Operand) arr.get(index2[j] - 1);
                    int num1 = Integer.parseInt(operand.getOperand());
                    Operand operand2 = (Operand) arr.get(index2[j] + 1);
                    int num2 = Integer.parseInt(operand2.getOperand());
                    int result = num1 + num2;
                    String str = Integer.toString(result); 
                    Operand change = new Operand(str); // carpmanın sonucu operand objesi olarak olarak arrarye eklenir
                    arr.set(index2[j] - 1, change);
                    arr.remove(index2[j]);
                    arr.remove(index2[j]);
                    ct++;
                    System.out.printf("%d: %s\n",ct,toString());
                }
                else if(o.getOperator().equals("-"))
                {
                    Operand operand = (Operand) arr.get(index2[j] - 1);
                    int num1 = Integer.parseInt(operand.getOperand());
                    Operand operand2 = (Operand) arr.get(index2[j] + 1);
                    int num2 = Integer.parseInt(operand2.getOperand());
                    int result = num1 - num2;
                    String str = Integer.toString(result); 
                    Operand change = new Operand(str); // bolmenin sonucu operand objesi olarak olarak arrarye eklenir
                    arr.set(index2[j] - 1, change);
                    arr.remove(index2[j]);
                    arr.remove(index2[j]);
                    ct++;
                    System.out.printf("%d: %s\n",ct,toString());
                }

                int newIndex = j + 1;
                // degisen arrayde, geriye kalan toplama ya da cıkarma indexleri bulunur
                for(int k=0; k < arr.size(); k++) //toplama ya da cıkarma varsa indexlerini bulur 
                {
                    if(arr.get(k) instanceof  Operator)
                    {
                        Operator op = (Operator) arr.get(k);
                        if(op.getOperator().equals("+"))
                        {
                            index2[newIndex] = k;
                            newIndex++;
                        }
                        else if(op.getOperator().equals("-"))
                        {
                            index2[newIndex] = k;
                            newIndex++;
                        }
                    }
                } 
            }
        }
        Operand result = (Operand) arr.get(0);
        int r = Integer.parseInt(result.getOperand()); 
        resultEvaluate = r;
    }
    /**
     * Expression objelerini string seklinde ifade etmeyi saglar
     * @return String
     */
    @Override
    public String toString() 
    {
        StringBuilder str = new StringBuilder();
        
        for(int l=0; l< arr.size(); l++)
        {
            if(arr.get(l) instanceof  Paranthesis)
            {
                Paranthesis p = (Paranthesis) arr.get(l);
                str.append(p.getPar()).append(" ");
            }
            else if(arr.get(l) instanceof  Operator)
            {
                Operator p = (Operator) arr.get(l);
                str.append(p.getOperator()).append(" ");
            }
            else if(arr.get(l) instanceof  Operand)
            {
                Operand p = (Operand) arr.get(l);
                str.append(p.getOperand()).append(" ");
            }
        
        }
   
        return  str.toString(); 
    }

    @Override
    public boolean equals(Object obj) 
    {
        Expression p;
        p = (Expression)obj;
        int result1, result2;
        result1 = resultEvaluate;
        result2 = p.resultEvaluate;
        return (result1 == result2); //To change body of generated methods, choose Tools | Templates.
    }

}
