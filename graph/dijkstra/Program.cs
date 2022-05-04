using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static List<string> processed = new List<string>();
    static Dictionary<string, Dictionary<string, int>> graph = new Dictionary<string, Dictionary<string, int>>();
    static Dictionary<string, int> costs = new Dictionary<string, int>();

    static Dictionary<string, string> parents = new Dictionary<string, string>();
    static void Main(string[] args)
    {

        graph["start"] = new Dictionary<string, int>() { { "a", 6 }, { "b", 2 } };
        graph["a"] = new Dictionary<string, int>();
        graph["a"]["fin"] = 1;
        graph["b"] = new Dictionary<string, int>();
        graph["b"]["a"] = 3;
        graph["b"]["fin"] = 5;
        graph["fin"] = new Dictionary<string, int>();

        var infinity = int.MaxValue;

        costs["a"] = 6;
        costs["b"] = 2;
        costs["fin"] = infinity;


        parents["a"] = "start";
        parents["b"] = "start";
        parents["fin"] = string.Empty;

        Dijkstr();

    }

    static void Dijkstr()
    {
        var node = FindLowestCostNode(costs);
        while (node != string.Empty)
        {
            var cost = costs[node];
            var neighorbs = graph[node];
            foreach (var n in neighorbs.Keys)
            {
                var new_cost = cost + neighorbs[n];
                if (costs[n] > new_cost)
                {

                    costs[n] = new_cost;
                    parents[n] = node;
                }
            }

            processed.Add(node);
            node = FindLowestCostNode(costs);

        }
    }

    static string FindLowestCostNode(Dictionary<string, int> costs)
    {
        var lowest_cost = int.MaxValue;
        var lowest_node = string.Empty;
        foreach (var node in costs)
        {
            if (node.Value < lowest_cost && !processed.Any(p => p == node.Key))
            {
                lowest_cost = node.Value;
                lowest_node = node.Key;
            }
        }

        return lowest_node;
    }

}
