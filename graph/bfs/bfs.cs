using System;
using System.Collections.Generic;
using System.Linq;

static class program
{
    static void Main()
    {

        find_short_path2();
    }

    static void find_short_path2()
    {
        var graph = new Dictionary<string, List<string>>();
        graph["cab"] = new List<string> { "cat", "car" };
        graph["car"] = new List<string> { "cat", "bar" };
        graph["cat"] = new List<string> { "bat", "mat" };
        graph["bar"] = new List<string>() { "bat" };
        graph["mat"] = new List<string> { "bat" };
        graph["bat"] = new List<string>();
        graph.Count();
        bfs_finish2(graph);
    }

    static bool bfs_finish2(Dictionary<string, List<string>> graph)
    {
        var queue = new Queue<string>();
        queue.AddRange<string>(graph["cab"]);

        while (queue.Any())
        {
            var p = queue.Dequeue();

            if (IsFinish2(p))
            {
                Console.WriteLine($"{p} is finish!");

                return true;
            }
            else
            {
                queue.AddRange<string>(graph[p]);
            }

        }
        return false;
    }

    static bool IsFinish2(string name)
    {
        return name == "bat";
    }


    static void find_short_path()
    {
        var graph = new Dictionary<string, List<string>>();
        graph["s"] = new List<string> { "1", "2" };
        graph["1"] = new List<string> { "3", "f" };
        graph["2"] = new List<string> { "3", "4" };
        graph["3"] = new List<string>();
        graph["4"] = new List<string> { "f" };
        graph["f"] = new List<string>();
        bfs_finish(graph);
    }

    static bool bfs_finish(Dictionary<string, List<string>> graph)
    {
        var queue = new Queue<string>();
        queue.AddRange<string>(graph["s"]);
        while (queue.Any())
        {
            var p = queue.Dequeue();
            if (IsFinish(p))
            {
                Console.WriteLine($"{p} is finish!");
                return true;
            }
            else
            {
                queue.AddRange<string>(graph[p]);
            }
        }
        return false;
    }

    static bool IsFinish(string name)
    {
        return name == "f";
    }


    static void find_mango_seller()
    {
        var graph = new Dictionary<string, List<string>>();
        graph["you"] = new List<string> { "alice", "bob", "claire" };
        graph["bob"] = new List<string> { "anuj", "peggy" };
        graph["alice"] = new List<string> { "peggy" };
        graph["claire"] = new List<string> { "thom", "jonny" };
        graph["anuj"] = new List<string>();
        graph["peggy"] = new List<string>();
        graph["thom"] = new List<string>();
        graph["jonny"] = new List<string>();

        bfs_seller(graph);
    }

    static bool bfs_seller(Dictionary<string, List<string>> graph)
    {
        var queue = new Queue<string>();
        queue.AddRange<string>(graph["you"]);
        while (queue.Any())
        {
            var p = queue.Dequeue();
            if (IsSeller(p))
            {
                Console.WriteLine($"{p} is mango seller!");
                return true;
            }
            else
            {
                queue.AddRange<string>(graph[p]);
            }
        }
        return false;
    }


    static bool IsSeller(string name)
    {
        return name[name.Length - 1] == 'm';
    }

    static void AddRange<T>(this Queue<T> queue, IEnumerable<T> enu)
    {
        foreach (T obj in enu)
            queue.Enqueue(obj);
    }


}