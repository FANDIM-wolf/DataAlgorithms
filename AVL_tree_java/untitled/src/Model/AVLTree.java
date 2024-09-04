package Model;
import  Model.Node;
public class AVLTree {
    Node root;

    // Метод для получения высоты узла
    int getHeight(Node node) {
        if (node == null) {
            return 0;
        }
        return node.height;
    }

    // Метод для обновления высоты узла
    void updateHeight(Node node) {
        node.height = Math.max(getHeight(node.left), getHeight(node.right)) + 1;
    }

    // Метод для получения баланса узла
    int getBalance(Node node) {
        if (node == null) {
            return 0;
        }
        return getHeight(node.left) - getHeight(node.right);
    }

    // Метод для левого поворота
    Node leftRotate(Node node) {
        Node temp = node.right;
        node.right = temp.left;
        temp.left = node;
        updateHeight(node);
        updateHeight(temp);
        return temp;
    }

    // Метод для правого поворота
    Node rightRotate(Node node) {
        Node temp = node.left;
        node.left = temp.right;
        temp.right = node;
        updateHeight(node);
        updateHeight(temp);
        return temp;
    }

    // Метод для балансировки дерева
    Node balance(Node node) {
        int balance = getBalance(node);
        if (balance > 1) {
            if (getHeight(node.left.left) >= getHeight(node.left.right)) {
                node = rightRotate(node);
            } else {
                node.left = leftRotate(node.left);
                node = rightRotate(node);
            }
        } else if (balance < -1) {
            if (getHeight(node.right.right) >= getHeight(node.right.left)) {
                node = leftRotate(node);
            } else {
                node.right = rightRotate(node.right);
                node = leftRotate(node);
            }
        }
        return node;
    }

    // Метод для вставки узла
    Node insert(Node node, int key) {
        if (node == null) {
            return new Node(key);
        }
        if (key < node.key) {
            node.left = insert(node.left, key);
        } else if (key > node.key) {
            node.right = insert(node.right, key);
        }
        updateHeight(node);
        node = balance(node);
        return node;
    }

    // Метод для обратного обхода дерева
    void reverseInorder(Node node) {
        if (node != null) {
            reverseInorder(node.left);
            reverseInorder(node.right);
            System.out.print(node.key + " ");
        }
    }

    // Метод для добавления узла в дерево
    public void add(int key) {
        root = insert(root, key);
    }

    // Метод для вывода дерева
    public void print() {
        reverseInorder(root);
    }
}
