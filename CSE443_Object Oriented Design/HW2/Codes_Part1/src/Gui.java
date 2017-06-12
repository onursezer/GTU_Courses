package src;


import java.awt.BorderLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;
import javax.swing.*;


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Onur
 */
public class Gui {
    
    private static List <Email> allAdress = new ArrayList<Email>();
    private static JFrame frame = null;
    private static JTextField pnameTxt,gnameTxt,surnameTxt,pmailTxt,gmailTxt,personelAddToGroupTxt,groupAddToGroupTxt;
    private static JButton personel, group, show, exit,
                   personelAddToBook, personelAddToGroup,
                  groupAddToBook, groupAddToGroup,personelAddToGroupBut,
                  groupAddToGroupBut;
    
    public Gui(){
        frame=new JFrame("AddresBook");
        frame.setLayout(new BorderLayout());
        frame.setSize(400,400);
        frame.setResizable(false);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        JPanel panel = new JPanel(new BorderLayout());        
        
        ImageIcon img = new ImageIcon("C:\\Users\\Onur\\Documents\\NetBeansProjects\\JavaApplication1\\src\\images\\personal.png");
        personel = new JButton(img);
        personel. setText("Personel Email");
        img = new ImageIcon("C:\\Users\\Onur\\Documents\\NetBeansProjects\\JavaApplication1\\src\\images\\group.png");
        group = new JButton(img);
        group.setText("Group Email");
        img = new ImageIcon("C:\\Users\\Onur\\Documents\\NetBeansProjects\\JavaApplication1\\src\\images\\mail.png");
        show = new JButton(img);
        show.setText("Show Emails");
        img = new ImageIcon("C:\\Users\\Onur\\Documents\\NetBeansProjects\\JavaApplication1\\src\\images\\exit.png");
        exit = new JButton(img);
        exit.setText("Exit      ");

        personel.setBounds(100, 53,160, 45);
        personel.addActionListener(new Action());
        group.setBounds(100, 109,160, 45);
        group.addActionListener(new Action());
        show.setBounds(100, 165,160, 45);
        show.addActionListener(new Action());
        exit.setBounds(100, 221,160, 45);
        exit.addActionListener(new Action());
        
        panel.add(personel);
        panel.add(group);
        panel.add(show);
        panel.add(exit);
        panel.setLayout(null);
        frame.add(panel);
        
    }
    
    static class Action implements ActionListener{


        @Override
        public void actionPerformed(ActionEvent e) {

            if(e.getSource()   ==  personel)
            {
                JFrame lframe=new JFrame("Personel Mail");
                //frame.setLayout(new BorderLayout());
                lframe.setSize(400,400);
                lframe.setResizable(false);
                lframe.setVisible(true);
                
                JPanel panel = new JPanel();
                panel.setLayout(null);
                
                JLabel nameLabel = new JLabel("Name          :");
                nameLabel.setBounds(50, 30, 120, 38);
                nameLabel.setFont(new Font("Arial", Font.BOLD, 18));
                
                pnameTxt =new JTextField();         
                pnameTxt.setBounds(180, 34, 120, 30);
                
                JLabel surnameLabel = new JLabel("Surname    :");
                surnameLabel.setBounds(50, 90, 120, 38);
                surnameLabel.setFont(new Font("Arial", Font.BOLD, 18));
                
                surnameTxt =new JTextField();         
                surnameTxt.setBounds(180, 94, 120, 30);
                
                JLabel mailLabel = new JLabel("Email          :");
                mailLabel.setBounds(50, 150, 120, 38);
                mailLabel.setFont(new Font("Arial", Font.BOLD, 18));
                
                pmailTxt =new JTextField();         
                pmailTxt.setBounds(180, 154, 120, 30);
 
                personelAddToBook = new JButton("Add to Book");
                personelAddToBook.addActionListener(new Action());
                personelAddToGroup = new JButton("Add to Group");
                personelAddToGroup.addActionListener(new Action());

                personelAddToBook.setBounds(50, 300, 120, 38);
                personelAddToGroup.setBounds(180, 300, 120, 38);

                panel.add(nameLabel);
                panel.add(pnameTxt);    
                panel.add(surnameLabel);
                panel.add(surnameTxt);
                panel.add(mailLabel);
                panel.add(pmailTxt);
                panel.add(personelAddToBook);
                panel.add(personelAddToGroup);
            
                //panel.setLayout(null);
                lframe.add(panel);
            }
            else if(e.getSource()   ==  group)
            {
                JFrame lframe=new JFrame("Group Mail");
                //frame.setLayout(new BorderLayout());
                lframe.setSize(400,400);
                lframe.setResizable(false);
                lframe.setVisible(true);
                
                JPanel panel = new JPanel();
                panel.setLayout(null);
                
                JLabel nameLabel = new JLabel("Name          :");
                nameLabel.setBounds(50, 30, 120, 38);
                nameLabel.setFont(new Font("Arial", Font.BOLD, 18));
                
                gnameTxt =new JTextField();         
                gnameTxt.setBounds(180, 34, 120, 30);
                
                
                JLabel mailLabel = new JLabel("Email          :");
                mailLabel.setBounds(50, 90, 120, 38);
                mailLabel.setFont(new Font("Arial", Font.BOLD, 18));
                
                gmailTxt =new JTextField();         
                gmailTxt.setBounds(180, 84, 120, 30);
                
                
                groupAddToBook = new JButton("Add to Book");
                groupAddToBook.addActionListener(new Action());
                groupAddToGroup = new JButton("Add to Group");
                groupAddToGroup.addActionListener(new Action());
  
        
                groupAddToBook.setBounds(50, 300, 120, 38);
                groupAddToGroup.setBounds(180, 300, 120, 38);

                panel.add(nameLabel);
                panel.add(gnameTxt);    
                panel.add(mailLabel);
                panel.add(gmailTxt);
                panel.add(groupAddToBook);
                panel.add(groupAddToGroup);
            
                //panel.setLayout(null);
                lframe.add(panel);
            }
            else if(e.getSource()   ==  personelAddToBook)
            {
                Email mail = new PersonalAddress(pnameTxt.getText(), 
                        surnameTxt.getText(),pmailTxt.getText());
                if(allAdress.add(mail))
                    JOptionPane.showMessageDialog(null, "PersonEmail was added");
                else
                    JOptionPane.showMessageDialog(null, "PersonEmail was not added");
            }
            else if(e.getSource()   ==  personelAddToGroup)
            {
                JFrame lframe=new JFrame("Personel Add To Group Mail");
                //frame.setLayout(new BorderLayout());
                lframe.setSize(400,300);
                lframe.setResizable(false);
                lframe.setVisible(true);
                
                JPanel panel = new JPanel();
                panel.setLayout(null);
                
                JLabel nameLabel = new JLabel("Group mail  :");
                nameLabel.setBounds(50, 30, 120, 38);
                nameLabel.setFont(new Font("Arial", Font.BOLD, 18));
                
                personelAddToGroupTxt =new JTextField();         
                personelAddToGroupTxt.setBounds(180, 34, 120, 30);
                
                personelAddToGroupBut = new JButton("Add to Group");
                personelAddToGroupBut.addActionListener(new Action());
                personelAddToGroupBut.setBounds(70, 80, 120, 38);
                
                panel.add(nameLabel);
                panel.add(personelAddToGroupTxt);
                panel.add(personelAddToGroupBut);
                lframe.add(panel);
            }
            else if(e.getSource() == personelAddToGroupBut)
            {
                boolean st = false;
                for (int i = 0; i < allAdress.size(); i++) {

                    if(allAdress.get(i) instanceof GroupAddress){
                       
                        if(allAdress.get(i).getAddress().equals(personelAddToGroupTxt.getText())){
                            st = true;
                            allAdress.get(i).add(new PersonalAddress(pnameTxt.getText(),surnameTxt.getText(),pmailTxt.getText()));
                            JOptionPane.showMessageDialog(null, "PersonelAddress was added");
                            break;
                        }
                    }
                }
                if(!st)
                    JOptionPane.showMessageDialog(null, "PersonelAddress was not added");
                
            }
            else if(e.getSource()   ==  groupAddToBook)
            {
                Email mail = new GroupAddress(gnameTxt.getText(),gmailTxt.getText());
                if(allAdress.add(mail))
                    JOptionPane.showMessageDialog(null, "GroupAddress was added");
                else
                    JOptionPane.showMessageDialog(null, "GroupAddress was not added");
            }
            else if(e.getSource()   ==  groupAddToGroup)
            {
                JFrame lframe=new JFrame("Group Add To Group Mail");
                //frame.setLayout(new BorderLayout());
                lframe.setSize(400,300);
                lframe.setResizable(false);
                lframe.setVisible(true);
                
                JPanel panel = new JPanel();
                panel.setLayout(null);
                
                JLabel nameLabel = new JLabel("Group mail  :");
                nameLabel.setBounds(50, 30, 120, 38);
                nameLabel.setFont(new Font("Arial", Font.BOLD, 18));
                
                groupAddToGroupTxt =new JTextField();         
                groupAddToGroupTxt.setBounds(180, 34, 120, 30);
                
                groupAddToGroupBut = new JButton("Add to Group");
                groupAddToGroupBut.addActionListener(new Action());
                groupAddToGroupBut.setBounds(70, 80, 120, 38);
                
                panel.add(nameLabel);
                panel.add(groupAddToGroupTxt);
                panel.add(groupAddToGroupBut);
                lframe.add(panel);
            }
            else if(e.getSource() == groupAddToGroupBut)
            {
                boolean st = false;
                for (int i = 0; i < allAdress.size(); i++) {

                    if(allAdress.get(i) instanceof GroupAddress){
                       
                        if(allAdress.get(i).getAddress().equals(groupAddToGroupTxt.getText())){
                            st = true;
                            for (int j = 0; j < allAdress.size(); j++) {

                                if(allAdress.get(j) instanceof GroupAddress){
                       
                                    if(allAdress.get(j).getAddress().equals(gmailTxt.getText())){
                                        allAdress.get(i).add(allAdress.get(j));
                                        JOptionPane.showMessageDialog(null, "PersonelAddress was added");
                                        break;
                                    }
                                }
                            }
                            allAdress.get(i).add(new GroupAddress(pnameTxt.getText(),pmailTxt.getText()));
                            JOptionPane.showMessageDialog(null, "PersonelAddress was added");
                            break;
                        }
                    }
                }
                if(!st)
                    JOptionPane.showMessageDialog(null, "PersonelAddress was not added");
                
            }
            else if(e.getSource()   ==  show)
            {
                JFrame lframe = new JFrame("AddressBook");
                final ArrayList<String> wordlist = new ArrayList<String>();
                for(Email a : allAdress)
                {
                    List<String> list = new ArrayList<String>();
                    a.printAddressGui(list);
                    for(String str : list)
                        wordlist.add(str);
                }

                JList<String> displayList = new JList<>(wordlist.toArray(new String[0]));
                JScrollPane scrollPane = new JScrollPane(displayList);
                lframe.getContentPane().add(scrollPane);
                lframe.pack();
                lframe.setSize(400,400);
                lframe.setVisible(true);
            }
            else if(e.getSource()   ==  exit)
            {
                frame.dispose();
            }

        }
    
    }
    public static void main(String []args)
    {
        System.out.println("Gui.main()");
        Gui gui = new Gui();
    }
   
}
