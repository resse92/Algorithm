

/**
  * 集合合并： 给定一个字符串的集合，格式如： {aaa bbb ccc},{bbb ddd},{eee fff},{ggg},{ddd hhh}
  * 要求将其中交集不为空的集合合并，要求合并完成后的集合之间无交集，例如上例应 输出 {aaa bbb ccc ddd hhh}，{eee fff}，{ggg} 
  * （1）请描述你解决这个问题的思路； 
  * （2）请给出主要的处理流程，算法，以及算法的复杂度
  * （3）请描述可能的改进（改进的方向如效果，性能等等，这是一个开放问题）。
  */
public
static void main(String[] args)
{
      NK_JH nkjh = new NK_JH();
      Scanner s = new Scanner(System.in);
      String say = s.nextLine();
      List<Set<String>> list = new ArrayList<Set<String>>();
      list = nkjh.getSet(list, say);
      nkjh.sortList(list);
      nkjh.mergerSet(list);
      for (Set<String> set : list)
    {
           for (String str : set)
        {
                System.out.print(str);
               
        }
           System.out.println();
          
    }
     
}
 /**
  * 将输入的集合转换为Set集合，存放在List中
  * 
  * @author wangyongbing
  * @param list
  *            存放Set的List
  * @param arg 格式
  *            ：{aaa bbb ccc}, {bbb ddd},{eee fff},{ggg},{ddd hhh}
  * @return
  * @since JDK 1.6
  */
    private List<Set<String>>
    getSet(List<Set<String>> list, String arg)
{
      if (null == arg)
    {
           return list;
          
    }
      Set<String> setSet = null;
      String[] args = arg.split(",");
      if (null == args)
    {
           return list;
          
    }
      for (String s : args)
    {
           String[] ss = s.replace("{", "").replace("}", "").split(" ");
           if (null == ss)
        {
                continue;
               
        }
           setSet = new HashSet<String>();
           for (String s1 : ss)
        {
                if (null == s1 || "".equals(s1.trim()))
            {
                     continue;
                    
            }
                setSet.add(s1.trim());
               
        }
           list.add(setSet);
          
    }
      return list;
     
}
 /**
  * 将list集合中的Set集合按照Set的大小排序,大->小
  * 
  * @author 
  * @param list
  * @since JDK 1.6
  */
 private void sortList(List<Set<String>> list)
{
      Collections.sort(list, new Comparator() {
   @Override
   public int compare(Object o1, Object o2) {
    Set<String> set1 = (Set<String>) o1;
    Set<String> set2 = (Set<String>) o2;
    return set2.size() - set1.size();
   }
   });
     
}
 /**
  * 将目标集合合并
  * 
  * @author 
  * @param list
  * @since JDK 1.6
  */
 private void mergerSet(List<Set<String>> list)
{
      if (null == list || list.size() < 2)
    {
           return;
          
    }
      Set<String> set1;
      Set<String> set2;
      int allSize = 0;
      for (int i = list.size(); i > 0; i--)
    {
           set1 = new HashSet<String>(list.get(i - 1));
        ;
           for (int j = i - 1; j > 0; j--)
        {
                set2 = new HashSet<String>(list.get(j - 1));
              
    allSize = set1.size() + set2.size();
                set2.addAll(set1);
                if (set2.size() < allSize)
            {
                     list.add(j - 1, set2);
                     list.remove(j);
                     list.remove(i - 1);
                     break;
                    
            }
               
        }
          
    }
     
}