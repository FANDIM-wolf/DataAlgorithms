import Model.*;
public class Main {
    public static void main(String[] args) {
        System.out.println("AVL tree");
        AVLTree tree = new AVLTree();
        tree.add(5);
        tree.add(3);
        tree.add(7);
        tree.add(2);
        tree.add(4);
        tree.add(6);
        tree.add(8);
        tree.print();
    }
}