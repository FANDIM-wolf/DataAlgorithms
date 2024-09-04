package Model;

public class Node {
    int key;
    Node left;
    Node right;
    int height;

    public Node(int key) {
        this.key = key;
        this.left = null;
        this.right = null;
        this.height = 1;
    }
}
