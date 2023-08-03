public class Node
{
    public int key;
    public Node nextNode;

    public Node(int key)
    {
        this.key = key;
    }
}

public static Node FindFirstCommonNode(Node head1, Node head2)
{
    if(head1 == null || head2 == null)
    {
        return null;
    }

    Stack<Node> stack1 = new Stack<Node>();
    Stack<Node> stack2 = new Stack<Node>();

    while(head1 != null)
    {
        stack1.Push(head1);
        head1 = head1.nextNode;
    }

    while(head2 != null)
    {
        stack2.Push(head2);
        head2 = head2.nextNode;
    }

    Node node1 = null;
    Node node2 = null;
    Node common = null;

    while(stack1.Count > 0 && stack2.Count > 0)
    {
        node1 = stack1.Peek();
        node2 = stack2.Peek();

        if (node1.key == node2.key)
        {
            common = node1;
            stack1.Pop();
            stack2.Pop();
        }
        else
        {
            break;
        }
    }

    return common;
}