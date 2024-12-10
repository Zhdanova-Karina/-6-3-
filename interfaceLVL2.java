import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;

public class Main {
    private Image imageLVL4; // Объект для хранения фона
    private Image buttonImageCage; // Объект для хранения текстуры кнопки
    private Image imageDalmatians; // Объект для хранения картинки с далматинцами
    private JButton buttonCage; // Кнопка "Клетка"
    private JButton buttonBox; // Кнопка "Коробка"
    private JButton buttonBarrel; // Кнопка "Бочка"
    private JLabel dalmatianLabel; // JLabel для изображения с далматинцами

    public Main() {
        try {
            // Загрузка изображения уровня
            imageLVL4 = ImageIO.read(new File("C:/Users/Karina/Desktop/Curse/img/подвал.png"));
            // Загрузка текстуры кнопки "Клетка"
            buttonImageCage = ImageIO.read(new File("C:/Users/Karina/Desktop/Curse/img/imgCage.jpg"));
            // Загрузка изображения с далматинцами
            imageDalmatians = ImageIO.read(new File("C:/Users/Karina/Desktop/Curse/img/далматинцы из клетки.jpg"));
        } catch (IOException e) {
            System.err.println("Ошибка загрузки изображения: " + e.getMessage());
            return; // Завершение метода при ошибке
        }

        createAndShowGUI();
    }

    private void createAndShowGUI() {
        JFrame frame = new JFrame("Показ изображения");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(1000, 650);
        frame.setLayout(null); // Используем абсолютное расположение

        // Панель для рисования изображения
        JPanel panel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                if (imageLVL4 != null) {
                    g.drawImage(imageLVL4, 0, 0, getWidth(), getHeight(), this); // Рисуем изображение
                }
            }
        };
        panel.setBounds(0, 0, 1000, 650); // Устанавливаем размер панели
        panel.setLayout(null); // Устанавливаем для панели абсолютное расположение

        // Создание кнопки "Клетка"
        buttonCage = new JButton(new ImageIcon(buttonImageCage));
        buttonCage.setBounds(800, 410, 155, 160); // Положение кнопки "Клетка"
        buttonCage.setBorderPainted(false);
        buttonCage.setContentAreaFilled(false);
        buttonCage.setFocusPainted(false);
        buttonCage.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                handleCageButtonAction(); // Метод для обработки нажатия кнопки "Клетка"
            }
        });

        // Добавление кнопки на панель
        panel.add(buttonCage);

        // Создание кнопки "Коробка"
        buttonBox = new JButton(new ImageIcon("C:/Users/Karina/Desktop/Curse/img/imgBox.jpg")); // Путь к изображению
        buttonBox.setBounds(373, 200, 350, 260); // Положение и размер кнопки "Коробка"
        buttonBox.setBorderPainted(false);
        buttonBox.setContentAreaFilled(false);
        buttonBox.setFocusPainted(false);
        buttonBox.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(frame, "Увы, тут никого нет!");
            }
        });
        panel.add(buttonBox);

        // Создание кнопки "Бочка"
        buttonBarrel = new JButton(new ImageIcon("C:/Users/Karina/Desktop/Curse/img/imgBarrel.jpg")); // Путь к изображению
        buttonBarrel.setBounds(30, 420, 132, 156); // Положение и размер кнопки "Бочка"
        buttonBarrel.setBorderPainted(false);
        buttonBarrel.setContentAreaFilled(false);
        buttonBarrel.setFocusPainted(false);
        buttonBarrel.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(frame, "Увы, тут никого нет!");
            }
        });
        panel.add(buttonBarrel);

        // Добавляем панель в окно
        frame.add(panel);
        frame.setVisible(true); // Делаем окно видимым
    }

    private void handleCageButtonAction() {
        // Создаем панель для диалогового окна
        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));

        // Создаем текстовое поле для ввода кода
        JTextField codeField = new JTextField();
        panel.add(new JLabel("Введите код:"));
        panel.add(codeField);

        // Создаем кнопку "Подсказка"
        JButton hintButton = new JButton("Подсказка");
        hintButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(panel, "В каком году был создан мультфильм 101 далматинец?"); // Подсказка
            }
        });
        panel.add(hintButton); // Добавляем кнопку подсказки на панель

        // Запрос кода у пользователя
        int option = JOptionPane.showConfirmDialog(null, panel, "Введите код", JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE);

        if (option == JOptionPane.OK_OPTION) {
            String code = codeField.getText(); // Получаем код из текстового поля
            if (code != null && (code.equals("1961"))) {
                // Если код правильный, отключаем кнопку "Клетка"
                buttonCage.setVisible(false); // Скрываем кнопку

                // Создаем JLabel для изображения далматинцев
                dalmatianLabel = new JLabel(new ImageIcon(imageDalmatians));
                dalmatianLabel.setBounds(800, 420, 155, 160); // Устанавливаем такие же координаты, как у кнопки
                ((JPanel) buttonCage.getParent()).add(dalmatianLabel); // Добавляем JLabel на панель
                ((JPanel) buttonCage.getParent()).repaint(); // Перерисовываем панель

                JOptionPane.showMessageDialog(null, "Поздравляю! Далматинец найден!"); // Сообщение о успехе
            } else {
                JOptionPane.showMessageDialog(null, "Неверный код! Попробуйте снова."); // Сообщение о неверном коде
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(Main::new); // Создаем и отображаем окно
    }
}
