using System.Collections.Generic;
using System.Linq;
using System;

class Program
{
    static List<string> final_stations = new List<string>();
    static void Main()
    {
        var states_needed = new List<string>() { "mt", "wa", "or", "id", "nv", "ut", "ca", "az" };
        var stations = new Dictionary<string, List<string>>();
        stations["kone"] = new List<string>() { "id", "nv", "ut" };
        stations["ktwo"] = new List<string>() { "id", "wa", "mt" };
        stations["kthree"] = new List<string>() { "or", "nv", "ca" };
        stations["kfour"] = new List<string>() { "nv", "ut" };
        stations["kfive"] = new List<string>() { "ca", "az" };
        Greedy(stations, states_needed);
        Print("final",final_stations);
    }

    static void Greedy(Dictionary<string, List<string>> stations, List<string> states_needed)
    {
        while (states_needed.Any())
        {
            var best_stations = "";
            var states_covered = new List<string>();
            foreach (var station in stations)
            {
                var covered = states_needed.Intersect(station.Value).ToList();
             
                if (covered.Count() > states_covered.Count())
                {
                    best_stations = station.Key;
                    states_covered = covered;
                }
            }
 
            states_covered.ForEach(s => states_needed.Remove(s));
      
            final_stations.Add(best_stations);
           
        }
    }

    static void Print(string s, List<string> arr)
    {
        Console.WriteLine(s);
        foreach (var item in arr)
        {
            Console.Write(item + "  ");
        }
        Console.WriteLine();
    }

}