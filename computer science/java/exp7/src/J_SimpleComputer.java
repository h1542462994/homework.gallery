package exp7;

import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import java.awt.*;
import java.util.Objects;

public class J_SimpleComputer extends JFrame {
    public static void main(String[] args){
        J_SimpleComputer frame = new J_SimpleComputer();
        frame.init();
    }

    private JTextField text1;
    private JTextField text2;
    private JTextField textResult;
    private JComboBox<String> comboBox;
    private JButton button;

    private void init(){
        this.setTitle("简单的计算机");
        this.add(GMainPanel());
        this.setSize(new Dimension(400,200));
        this.setMinimumSize(new Dimension(400,200));
        this.setVisible(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.registryEvent();
        updateStatus();
    }

    private void registryEvent(){
        text1.getDocument().addDocumentListener(new DocumentListener() {
            @Override
            public void insertUpdate(DocumentEvent e) {
                updateStatus();
            }

            @Override
            public void removeUpdate(DocumentEvent e) {
                updateStatus();
            }

            @Override
            public void changedUpdate(DocumentEvent e) {
                updateStatus();
            }
        });

        text2.getDocument().addDocumentListener(new DocumentListener() {
            @Override
            public void insertUpdate(DocumentEvent e) {
                updateStatus();
            }

            @Override
            public void removeUpdate(DocumentEvent e) {
                updateStatus();
            }

            @Override
            public void changedUpdate(DocumentEvent e) {
                updateStatus();
            }
        });

        button.addActionListener(e->{
            int value1 = Integer.valueOf(text1.getText());
            int value2 = Integer.valueOf(text2.getText());
            String op = Objects.requireNonNull(comboBox.getSelectedItem()).toString();
            int result = 0;

            if(op.equals("+"))
                result = value1 + value2;
            else if(op.equals("-"))
                result = value1 - value2;
            else if(op.equals("*"))
                result = value1 * value2;
            else{
                if(value2 == 0){
                    JOptionPane.showMessageDialog(this,"除数不能为0");
                } else {
                    result = value1 / value2;
                }
            }

            textResult.setText(String.valueOf(result));
        });
    }

    private JPanel GMainPanel(){
        JPanel root= new JPanel();
        FlowLayout layout = new FlowLayout(FlowLayout.CENTER,10,10);
        root.setLayout(layout);

        text1 = new JTextField();
        text1.setPreferredSize(new Dimension(60,30));
        root.add(text1);
        comboBox = new JComboBox<>();
        comboBox.addItem("+");
        comboBox.addItem("-");
        comboBox.addItem("*");
        comboBox.addItem("/");

        comboBox.setPreferredSize(new Dimension(60,30));

        root.add(comboBox);
        text2 = new JTextField();
        text2.setPreferredSize(new Dimension(60,30));
        root.add(text2);
        button = new JButton();
        button.setText("=");
        button.setPreferredSize(new Dimension(60,30));
        root.add(button);
        textResult = new JTextField();
        textResult.setPreferredSize(new Dimension(60,30));
        root.add(textResult);

        root.setForeground(Color.CYAN);
        return root;
    }
    private void updateStatus(){
        if(isDigit(text1.getText()) && isDigit(text2.getText())){
            button.setEnabled(true);
        } else {
            button.setEnabled(false);
        }
    }

    private boolean isDigit(String value){
        try {
            int a = Integer.valueOf(value);
            return true;
        } catch (NumberFormatException e){
            return false;
        }
    }
}
