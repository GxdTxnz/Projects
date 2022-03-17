import java.util.Comparator;

public class AVLTree<K, V> 
{
    // Корневой узел
    private AVLNode<K, V> root;
    // Максимальная разница между левым деревом сбалансированного двоичного дерева и правым деревом
    private static final int MAX_AVL_ALLOW_LIMIT = 1;
    // Максимальная разница между правым деревом сбалансированного двоичного дерева и левым деревом
    private static final int MIN_AVL_ALLOW_LIMIT = -1;
    // Ключевой компаратор
    private Comparator<K> comparator;
    // Текущий размер дерева
    private int size = 1;
    public AVLTree(Comparator<K> comparator) 
    {
        this.comparator = comparator;
    }
    public void add(K key, V value) 
    {
        AVLNode<K, V> node = new AVLNode<>(key, value);
        // Если корень пуст, инициализируем
        if (root == null) 
        {
            root = node;
            return;
        }
        // вставляем
        insert(root, node);
        // Сбалансированное двоичное дерево
        balance(node);
    }
    public void remove(K key)
    {
        AVLNode<K, V> node = find(root, key);
        if (node == null) return;
        // Удаляется верхний узел
        if(root == node) 
        {
            // Левое поддерево пусто
            if(node.left == null) root = root.right;
            // Случай, когда правое поддерево пусто
            else if(node.right == null) root = root.left;
            else 
            {
                AVLNode<K,V> tNode = node.left.right;
                node.left.setNode(node.right, AVLNode.RIGHT_NODE_INDEX);
                node = node.left;
                node.setNode(null, AVLNode.PARENT_NODE_INDEX); // Позиция родительского узла равна нулю
                // Левое поддерево висит ниже левого поддерева правого поддерева
                leftNodeMoveRightNode(node, tNode);
                root = node;
            }
        }
        // Удаление конечного узла
        else if(node.left == null && node.right == null) 
        {
           node.parent.removeLeaf(node.parent.isChildNode(node));
        }
        // Корневой узел удаляется, и сначала заменяется левый узел
        else 
        {
            AVLNode<K,V> pNode = node.parent;
            int index = pNode.isChildNode(node);
            pNode.removeLeaf(index);
            if (node.left != null) 
            {
                pNode.setNode(node.left, index);
                // Если правое поддерево корневого узла левого поддерева не пусто
                AVLNode<K, V> rNode = node.left.right;
                if(rNode != null) 
                {
                    if(node.right != null) 
                    {
                        leftNodeMoveRightNode(node, rNode);
                    }
                    node.left.setNode(node.right, AVLNode.RIGHT_NODE_INDEX); // Устанавливаем правый узел
                }
            } 
            else 
            {
                // Устанавливаем правый узел напрямую
                pNode.setNode(node.right, index);
            }
        }
        size--;
        // Получение самого нижнего листового узла корневого дерева и проверка баланса
        balance(findLowestLeafNode(root));
    }
    // Левое поддерево висит ниже левого поддерева правого поддерева
    private void leftNodeMoveRightNode(AVLNode<K, V> node, AVLNode<K, V> tNode) 
    {
        AVLNode<K, V> rrlNode = node.right;
        do 
        {
            rrlNode = rrlNode.left;
        } 
        while (rrlNode.left != null);// Получаем крайний левый узел правого поддерева

        rrlNode.setNode(tNode, AVLNode.LEFT_NODE_INDEX); // Преобразуем правый узел левого узла в правый узел
    }

    public V get(K key) 
    {
         AVLNode<K, V> node = find(root, key);
         return node == null ? null : node.value;
    }
    // Рекурсивный запрос, если объем данных слишком велик, может возникнуть риск переполнения стека методов
    private AVLNode<K, V> find(AVLNode<K, V> node, K key) 
    {
        if (node == null) return null;
        int val = comparator.compare(node.key, key);
        if (val == 0) return node;
        if (val > 0) return find(node.left, key);
        return find(node.right, key);
    }
    // Вывести корневой узел (включая поддерево)
    public void printTree() 
    {
        // Получаем высоту двоичного дерева
        int height = height(root);
        // Массив приложения
        Object[] arr = new Object[2 << height - 1];
        // Связанный список с массивом двоичного дерева
        linkedTransferArray(arr, root, 1);
        // длина
        int maxSpaceCount = 2 << height;
        // Обходим массив
        for (int i = 0; i < height; i++) 
        {
            StringBuffer sb = new StringBuffer();
            int nodes = (((2 << (i - 1)) + 1) == 1 ? 2 : ((2 << (i - 1)) + 1));
            if (i == height - 1) nodes -= 1;
            int spaceCount = (maxSpaceCount - nodes) / nodes;
            // Распечатываем переднее пространство
            for (int i1 = 0; i1 < spaceCount; i1++) 
            {
                sb.append(" ");
            }
            // Распечатываем содержимое массива
            int indexLimit = (2 << i) - 1;
            int i3 = ((2 << (i - 1)) - 1) == -1 ? 0 : (2 << (i - 1)) - 1;
            for (int i1 = i3; i1 < indexLimit; i1++) 
            {
                if (arr[i1] != null) sb.append(arr[i1]);

                for (int i2 = 0; i2 < spaceCount; i2++) sb.append(" ");
            }
            System.out.println(sb);
            sb = new StringBuffer();
            // Распечатываем переднее пространство
            nodes = (((2 << i) + 1) == 1 ? 2 : ((2 << i) + 1));
            if (i == height - 2) nodes -= 1;
            spaceCount = (maxSpaceCount - nodes) / nodes;
            for (int i1 = 0; i1 < spaceCount; i1++) 
            {
                sb.append(" ");
            }
            // Распечатать ветки
            for (int i1 = i3; i1 < indexLimit; i1++) 
            {
                if (arr.length > i1 * 2 + 1 && arr[i1 * 2 + 1] != null) sb.append("/");
                // Интервал перед ветками
                for (int i2 = 0; i2 < spaceCount; i2++) sb.append(" ");

                if (arr.length > (i1 * 2 + 2) && arr[i1 * 2 + 2] != null) sb.append("\\");
                // Пространство за ветками
                for (int i2 = 0; i2 < spaceCount; i2++) sb.append(" ");
            }
            System.out.println(sb);
        }
    }
    public int size() 
    {
        return size;
    }
    private void insert(AVLNode<K, V> tNode, AVLNode<K, V> sNode) 
    {
        if (comparator.compare(tNode.key, sNode.key) < 0) 
        {
            // Если корень меньше, правый узел
            if (tNode.right == null) 
            {
                tNode.right = sNode;
                sNode.parent = tNode;
                size++;
                return;
            }
            insert(tNode.right, sNode);
        } 
      else if (comparator.compare(tNode.key, sNode.key) > 0) 
      {
            // Если корень больше, левый узел
            if (tNode.left == null) 
            {
                tNode.left = sNode;
                sNode.parent = tNode;
                size++;
                return;
            }
            insert(tNode.left, sNode);
        } 
        else 
        {
            // Если ключи равны, обновляем значение
            tNode.value = sNode.value;
        }
    }
    // Преобразуем древовидную структуру в структуру массива для удобства печати (ненормальная сортировка)
    private void linkedTransferArray(Object[] arr, AVLNode<K, V> node, int index) 
    {
        if (node == null) return;
        arr[index - 1] = node;
        if (node.left != null)
            linkedTransferArray(arr, node.left, index * 2);
        if (node.right != null)
            linkedTransferArray(arr, node.right, index * 2 + 1);
    }
    // Рассчитываем максимальную высоту дерева
    private int height(AVLNode<K, V> node) 
    {
        if (node == null) return 0;
        return Math.max(height(node.left), height(node.right)) + 1;
    }
    // Получаем самый низкий листовой узел
    private AVLNode<K, V> findLowestLeafNode(AVLNode<K, V> node) 
    {
        if (node == null) return null;
        if (node.left == null && node.right == null) return node;
        int maxDeep = height(node);
        AVLNode<K, V> cNode = node;
        int cHeight = 0;
        int direction = 0; // 0 означает вниз, 1 означает вверх
        do 
        {
            // Листовой узел
            if (cNode.left == null && cNode.right == null) 
            {
                if (cHeight + 1 == maxDeep) 
                {
                    break;
                }
                else 
                {
                    //Найди
                    // Получаем последний корневой узел
                    AVLNode<K, V> root = cNode;
                    // Если это левый узел, то вернемся прямо
                    if (cNode.parent.isChildNode(cNode) == AVLNode.LEFT_NODE_INDEX) 
                    {
                        do 
                        {
                            cHeight--;// Отслеживание текущего слоя с возвратом
                            root = root.parent;
                        }
                        while(root.parent.right == null);
                     } 
                     else 
                     {
                        // Если правому узлу нужно продолжить поиск с возвратом
                        AVLNode<K, V> tmp = null;
                        do 
                        {
                            // Оцениваем, левый ли это узел
                            tmp = root;
                            root = root.parent;
                            cHeight--; // Отслеживание текущего слоя с возвратом
                        } 
                        while (root.isChildNode(tmp) == AVLNode.RIGHT_NODE_INDEX);
                     }
                   cNode = root; // Смещение к предыдущему корневому узлу, который не прошел правое поддерево, и поддерево не пусто
                   direction = 1;
                }
            } 
            else 
            {
                // Находим вниз
                // Сначала левый узел
                if (cNode.left != null && direction == 0) 
                {
                    cNode = cNode.left;
                } 
                else 
                {
                    if(cNode.right == null) 
                    {
                        cNode = cNode.parent;
                        continue; // Если правый узел пуст
                    }
                    cNode = cNode.right;
                    direction = 0;
                }
                cHeight++; //add height
            }
        } 
        while (true);
        return cNode;
    }
    // Баланс двоичного дерева, обнаружение и корректировка положения узла, чтобы обеспечить максимальную высоту дерева
    private void balance(AVLNode<K, V> node) 
    {
        do 
        {
            int val = height(node.left) - height(node.right);
            if (val > MAX_AVL_ALLOW_LIMIT) 
            {
                // Левое поддерево слишком длинное
                // Оценка типа длины
                val = height(node.left.left) - height(node.left.right);
                if (val > 0) 
                {
                    // правая рука типа LL
                    rightRotation(node);
                } 
                else 
                {
                    // Тип LR левая -> правая
                    leftRotation(node.left);
                    rightRotation(node);
                }
            }
            if (val < MIN_AVL_ALLOW_LIMIT) 
            {
                // Правое поддерево слишком длинное
                // Оценка типа длины
                val = height(node.right.left) - height(node.right.right);
                if (val < 0) 
                {
                    // Тип RR левый
                    leftRotation(node);
                }
                if (val > 0) 
                {
                    // Тип RL правая -> левая
                    rightRotation(node.right);
                    leftRotation(node);
                }
            }
            node = node.parent;
        } 
        while (node != null);
    }
    //Повернуть налево
    private void leftRotation(AVLNode<K, V> node) 
    {
        replaceNodeParent(node.right, node);
        AVLNode<K, V> tmp = node.right.left;
        node.right.left = node;
        node.right = tmp;
        if(node.right != null) node.right.parent = node;
    }
    // Повернуть вправо
    private void rightRotation(AVLNode<K, V> node) 
    {
        replaceNodeParent(node.left, node);
        AVLNode<K, V> tmp = node.left.right;
        node.left.right = node;
        node.left = tmp;
        if(node.left != null) node.left.parent = node;
    }
    // Заменить родительский элемент родительского узла новым узлом и установить родительский элемент нового узла на родительский элемент родительского узла
    private void replaceNodeParent(AVLNode<K, V> newNode, AVLNode<K, V> oldNode) 
    {
        if (oldNode == null) return;
        // Определяем, есть ли у родителя родительский узел
        if (oldNode.parent == null) 
        {
            newNode.parent = null;
            root = newNode;
        } 
        else 
        {
            // Убедитесь, что родительский узел является левым или правым узлом родительского узла
            if (oldNode.parent.isChildNode(oldNode) == AVLNode.LEFT_NODE_INDEX) 
            {
                oldNode.parent.left = newNode;
            } 
            else 
            {
                oldNode.parent.right = newNode;
            }
        }
        // Заменим родительский узел старого на newNode
        newNode.setNode(oldNode.parent, AVLNode.PARENT_NODE_INDEX);
        oldNode.setNode(newNode, AVLNode.PARENT_NODE_INDEX);
    }
    // узел узел
    class AVLNode<K, V> 
    {
        final K key;
        V value;
        AVLNode<K, V> left;
        AVLNode<K, V> right;
        AVLNode<K, V> parent;
        static final int PARENT_NODE_INDEX = 0;
        static final int LEFT_NODE_INDEX = 1;
        static final int RIGHT_NODE_INDEX = 2;
        AVLNode(K key, V value) 
        {
            this.key = key;
            this.value = value;
        }
        // Удаляем листовые узлы
        //1.left 2.right
        void removeLeaf(int index) 
        {
            if(index == LEFT_NODE_INDEX) 
            {
                left.parent = null;
                left = null;
            }
            if(index == RIGHT_NODE_INDEX) 
            {
                right.parent = null;
                right = null;
            }
        }
        // Определяем, является ли это родительским узлом
        //return 1.left 2.right
        int isChildNode(AVLNode<K, V> node) 
        {
            if(node == left) return LEFT_NODE_INDEX;
            if(node == right) return RIGHT_NODE_INDEX;
            return -1;
        }
        void setNode(AVLNode<K, V> node, int index) 
        {
            switch (index) 
            {
                case PARENT_NODE_INDEX:
                    parent = node;
                    break;
                case LEFT_NODE_INDEX:
                    if(left != null) left.parent = null;
                    left = node;
                    if(node != null) node.parent = this;
                    break;
                case RIGHT_NODE_INDEX:
                    if(right != null) right.parent = null;
                    right = node;
                    if(node != null) node.parent = this;
                    break;
            }
        }

        @Override
        public String toString() 
        {
            return key.toString();
        }
    }
}

