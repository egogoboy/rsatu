import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Vector;
import java.util.Collections;

class MyException extends IOException {
    public MyException(String msg) {
        message = msg;
    }

    public String getMessage() {
        return "Error: " + message;
    }

    private final String message;
}

public class Main {
    public static void main(String[] args) {
        if (args.length == 0) {
                    System.out.println("Ошибка: не указан файл для чтения.");
                    return;
        }
        try (FileReader reader = new FileReader(args[0])) {
            Vector<String> input_strings = getInputStrings(reader);
            String example = getExample();
            Map<Integer, Vector<String>> result = new HashMap<>();
            Vector<Integer> frequences = new Vector<>();

            for (String inputString : input_strings) {
                int cur_frequency = getCurFrequency(inputString, example);
                addFrequencyToResult(result, frequences, cur_frequency, inputString);
            }

            try {
                StringBuilder output = getOutputString(result, frequences);
                System.out.println(output.toString());
            } catch (MyException my_ex) {
                System.out.println(my_ex.getMessage());
            }
        } catch (IOException ex) {
            System.out.println(ex.getMessage());
        }
    }

    private static void addFrequencyToResult(Map<Integer, Vector<String>> result, 
                                             Vector<Integer> frequences, 
                                             int frequency, 
                                             String inputString) {
        result.computeIfAbsent(frequency, k -> {
            frequences.add(k);
            return new Vector<>();
        }).add(inputString);
    }

    private static StringBuilder getOutputString(Map<Integer, Vector<String>> result, 
                                                 Vector<Integer> frequences) throws MyException {
        StringBuilder output = new StringBuilder();
        if (frequences == null) {
            throw new MyException("Null result vector");
        }

        Collections.sort(frequences);
        for (int i = frequences.size() - 1; i >= 0; --i) {
            for (String word : result.get(frequences.get(i))) {
                output.append(word + ": " + frequences.get(i) + '\n');
            }
        }

        return output;
    }

    private static int getCurFrequency(String inputString, String example) {
        int cur_frequency = 0;
        for (int i = 0; i < inputString.length(); ++i) {
            if (inputString.charAt(i) == example.charAt(0)) {
                int first = i + 1;
                int second = 1;
                while (first < inputString.length() && second < example.length()
                    && inputString.charAt(first) == example.charAt(second)) {
                    ++first;
                    ++second;
                }
                if (second == example.length()) {
                    ++cur_frequency;
                }
            }
        }

        return cur_frequency;
    }

    private static Vector<String> getInputStrings(FileReader reader) {
        try (Scanner scanner = new Scanner(reader)) {
            Vector<String> input_strings = new Vector<String>();

            System.out.print("Строки для проверки:\n");
            while (scanner.hasNextLine()) {
                String s = scanner.nextLine();
                input_strings.add(s);
                System.out.println(s);
            }

            return input_strings;
        }
    }

    private static String getExample() {
        try (Scanner in = new Scanner(System.in)) {
            System.out.print("Введите строку для проверки на вхождение: ");
            String example = in.nextLine();

            return example;
        }
    }
}
