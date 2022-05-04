using System;
using System.Collections.Generic;
using System.Linq;

static class program
{
    static void Main(){
         var graph = new Dictionary<string,List<string>>();
        graph["you"] = new List<string> {"alice","bob","claire"};
        graph["bob"] = new List<string> {"anuj","peggy"};       
        graph["alice"] = new List<string> {"peggy"};       
        graph["claire"] = new List<string> {"thom","jonny"};
        graph["anuj"] = new List<string>();
        graph["peggy"] = new List<string>();
        graph["thom"] = new List<string>();
        graph["jonny"] = new List<string>();
       
        bfs(graph);

    }

    static bool bfs(Dictionary<string,List<string>> graph){
        var queue = new Queue<string>();               
        queue.AddRange<string>(graph["you"]);
        while (queue.Any())
        {
            var p = queue.Dequeue();
            if(IsSeller(p)){
                Console.WriteLine($"{p} is mango seller!");
                return true;
            }else{
                queue.AddRange<string>(graph[p]);
            }
        }       
        return false;       
    }

     static bool IsSeller(string name){
        return name[name.Length-1] =='m';
    }

   static void AddRange<T>(this Queue<T> queue, IEnumerable<T> enu) {
        foreach (T obj in enu)
            queue.Enqueue(obj);
  }
}