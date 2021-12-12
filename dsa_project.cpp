#include <iostream>

using namespace std;
void dist();
void time();
bool visited[7];
bool visited1[7];
int dis[7];
int f = 0;
int r = 0;
int add2[7][7];
int parent[7];
int vertex[7];
int dis1[7];
int parent1[7];
string vertices[7] = {
    "LAHORE",
    "Rawalpindi",
    "Karachi",
    "Peshawar",
    "Quetta",
    "Multan",
    "Faisalabad"};
string form[7] = {
    "L",
    "R",
    "K",
    "P",
    "Q",
    "M",
    "F"};
    
int add[7][7];
void bfs(int);
void breadthFirstSearch();
int add1[7][7];
int stack[10];
int top = -1;
int stack1[10];
void path1(int);
void path2(int);
int top1 = -1;
void addEdge(int, int, int);
void addEdge1(int, int, int);
void push(int);
void pop();
void push1(int);
void pop1();
void display();
void display1();
void display2();
void display3();
void both();
int shortestpath(int, int, int);
int shortestpath1(int, int, int);
int weight[20];
int parent2[7];
int list[7][7];
int queue[100];
bool arr[7];
bool visited2[7];
void kruskal();
int list1[7];

int main()
{
  int n;
  int V = 7;
  for (int k = 0; k < V; k++)
  {
    vertex[k] = k;
  }
  for (int gk = 0; gk < 7; gk++)
  {
    cout << vertices[gk] << " \n";
    cout << vertex[gk] << "  \n";
  }
  cout << "\n";

  for (int j = 0; j < V; j++)
  {
    dis[j] = 0;
    visited[j] = false;
    dis1[j] = 0;
    visited1[j] = false;
    arr[j] = false;
  }
  cout << "The weight graph in which weight depend upon distance \n";
  addEdge(0, 3, 4);

  addEdge(0, 1, 2);
  addEdge(0, 5, 5);
  addEdge(0, 3, 4);
  addEdge(1, 3, 1);
  addEdge(1, 4, 3);
  addEdge(3, 4, 2);
  addEdge(1, 2, 7);
  addEdge(2, 4, 10);
  addEdge(1, 5, 8);
  addEdge(1, 6, 4);
  addEdge(5, 6, 1);
  addEdge(6, 2, 6);
  display();
  
  cout << " \n The weighted graph in which weight depend upon time \n";

  addEdge1(0, 1, 2);	
  addEdge1(0, 5, 5);
  addEdge1(0, 3, 2);
  addEdge1(1, 3, 4);
  addEdge1(1, 4, 3);
  addEdge1(3, 4, 2);
  addEdge1(1, 2, 7);
  addEdge1(2, 4, 2);
  addEdge1(1, 5, 8);
  addEdge1(1, 6, 8);
  addEdge1(5, 6, 3);
  addEdge1(6, 2, 6);

  display1();
  int s = 0;
  for (int i = 0; i < 7; i++)
  {
    for (int j = 0; j < 7; j++)
    {
      if (add2[i][j] > 0)
      {
        weight[s] = add2[i][j];
        s++;
      }
    }
  }
  for (int w = 0; w < s; w++)
  {
    for (int r = 0; r < s; r++)
    {
      if (weight[w] < weight[r])
      {
        int temp = weight[w];
        weight[w] = weight[r];
        weight[r] = temp;
      }
    }
  }
  for (int p = 0; p < s; p++)
  {
    for (int y = p + 1; y < s; y++)
    {
      if (weight[p] == weight[y])
      {
        int a = y;
        while (a < s)
        {
          weight[a] = weight[a + 1];
          a++;
        }
      }
    }
  }
  for (int e = 0; e < 7; e++)
  {
    parent2[e] = e;
    visited2[e] = false;
  }

  cout << "Press 1 to get shortest path for distance" << endl;
  cout << "Press 2 to get shortest path for time" << endl;
  cout << "Press 3 to get shortest path for both time and distance" << endl;
  cout << "Press 4 to get minimum spanning tree" << endl;
  cout << "Press 5 to get level order traversal of tree" << endl;
  
  while (n != 0)
  {
    cout << "Enter your choice:" << endl;
    cin >> n;
    switch (n)
    {
    case 1:
      dist();
      break;
    case 2:
      time();
      break;
    case 3:
      both();
      break;
    case 4:
      kruskal();
      break;
    case 5:
      breadthFirstSearch();
      break;
    }
  }
}
void breadthFirstSearch()
{
  bfs(0);
}
void bfs(int start)
{
  f++;
  r++;
  queue[f] = start;
  int d = queue[f];
  int si = -1;
  int li = -1;
  for (int i = 0; i < 7; i++)
  {
    if (i == start)
    {
      arr[i] = true;
      si++;
      li++;
      list1[si] = start;
    }
  }
  while (f < r + 1)
  {
    for (int j = 0; j < 7; j++)
    {
      if (add[d][j] > 0)
      {
        if (arr[j] == false)
        {
          arr[j] = true;
          r++;
          queue[r] = j;
          li++;
          list1[li] = j;
        }
      }
    }

    f = f + 1;
    d = queue[f];
  }
  int w = si;
  cout << "The BSF traversal of the graph is " << endl << endl;
  while (si <= li)
  {
    cout << list1[si] << "\t\t ";
    si++;
  }
  cout << endl;
  while (w <= li)
  {
    int t = list1[w];
    cout << vertices[t] << "  | ";

    w++;
  }
  f = 0;
  r = 0;
  for (int p = 0; p < 7; p++)
  {
    arr[p] = false;
  }
  cout << "\n \n";
}
void kruskal()
{
  int v = 7;
  int edge = 0;
  int si = 0;
  int count = 0;
  while (edge <= v - 1)
  {
    int w = weight[si];
    for (int i = 0; i < 7; i++)
    {
      for (int j = 0; j < 7; j++)
      {
        if (add2[i][j] == w && visited2[i] == false && visited2[j] == false)
        {
          parent2[i] = i;
          parent2[j] = i;
          list[i][j] = w;
          visited2[i] = true;
          visited2[j] = true;
        }
        else if (add2[i][j] == w && visited2[i] == false && visited2[j] == true)
        {

          parent2[i] = parent2[j];
          visited2[i] = true;
          list[i][j] = w;
        }
        else if (add2[i][j] == w && visited2[i] == true && visited2[j] == false)
        {

          parent2[j] = parent2[i];
          visited2[j] = true;
          list[i][j] = w;
        }
        else if (add2[i][j] == w && visited2[i] == true && visited2[j] == true)
        {

          if (parent2[i] == parent2[j])
          {

            list[i][j] = 0;
          }
          else
          {
            int x = parent2[j];
            parent2[j] = parent2[i];
            parent2[x] = parent2[i];
            list[i][j] = w;
          }
        }
      }
    }
    si++;
    edge++;
  }
  cout << "Original Tree tabel and connections" << endl;
  display2();
  cout << endl;
  int cost1 = 0;
  int cost2 = 0;
  for (int c = 0; c < 7; c++)
  {
    for (int d = 0; d < 7; d++)
    {
      if (add2[c][d] > 0)
      {
        int y = c;
        int r = d;
        cout << "Connection between " << vertices[y] << " " << vertices[r] << endl;
        cost1 = cost1 + add2[c][d];
      }
    }
  }
  cout << "Total cost of original is " << cost1 << endl << endl << endl;
  cout << "Minimum Spanning Tree connection and tabel" << endl;
  display3();
  for (int b = 0; b < 7; b++)
  {
    for (int bn = 0; bn < 7; bn++)
    {
      if (list[b][bn] > 0)
      {
        int y = b;
        int r = bn;
        cout << "Connection between " << vertices[y] << " " << vertices[r] << "\n";
        cost2 = cost2 + list[b][bn];
      }
    }
  }
  cout << "\n";

  cout << "After reducing into Minimum Spanning Tree total cost is: " << cost2 << " \n";
  for (int s = 0; s < 7; s++)
  {
    visited2[s] = false;
  }
}
void display2()
{
  for (int i = 0; i < 7; i++)
  {
    for (int j = 0; j < 7; j++)
    {
      cout << add2[i][j] << "   ";
    }
    cout << "\n";
  }
}

void display3()
{
  for (int i = 0; i < 7; i++)
  {
    for (int j = 0; j < 7; j++)
    {
      cout << list[i][j] << "  ";
    }
    cout << " \n";
  }
}

void dist()
{

  int d;

  cout << "Enter destination point" << endl;
  cin >> d;
  int g = shortestpath(0, d, 7);
  path1(d);
  cout << "\n";
}
void time()
{

  int d;

  cout << "Enter destination point \n";
  cin >> d;
  int g = shortestpath1(0, d, 7);
  path2(d);
  cout << " \n";
}
void both()
{
  int s;
  int d;

  cout << "Enter destination point \n";
  cin >> d;
  int g = shortestpath(0, d, 7);
  int k = shortestpath1(0, d, 7);
  if (g < k)
  {
    path1(d);
    cout << "Total time travel is " << k << " minutes \n";
  }
  else
  {
    path2(d);
    cout << "Total distance travel is " << g << " km \n";
  }
}
void addEdge(int u, int v, int w)
{
  add[u][v] = w;
  add[v][u] = w;
  add2[u][v] = w;
}
void addEdge1(int u, int v, int w)
{
  add1[u][v] = w;
  add1[v][u] = w;
}

void display()
{
  for (int k = 0; k < 7; k++)
  {
    cout << form[k] << " ";
  }
  cout << " \n\n";
  for (int i = 0; i < 7; i++)
  {
    for (int j = 0; j < 7; j++)
    {

      cout << add[i][j] << " ";
    }
    cout << "\n";
  }
  cout << " \n";
}
void display1()
{
  for (int k = 0; k < 7; k++)
  {
    cout << form[k] << " ";
  }
  cout << " \n\n";
  for (int i = 0; i < 7; i++)
  {

    for (int j = 0; j < 7; j++)
    {

      cout << add1[i][j] << " ";
    }
    cout << "\n";
  }
  cout << " \n";
}
int shortestpath(int start, int end, int v)
{
  int wp = start;
  int j = 0;
  parent[start] = 0;
  dis[start] = 0;
  while (j < v)
  {
    visited[start] = true;
    for (int i = 0; i < v; i++)
    {
      if (add[start][i] > 0 && visited[i] == false)
      {
        if (dis[i] == 0)
        {
          dis[i] = dis[start] + add[start][i];
          parent[i] = start;
        }
        else
        {
          int t = dis[start] + add[start][i];
          if (t < dis[i])
          {
            dis[i] = t;
            parent[i] = start;
          }
        }
      }
    }
    int min;
    int index;
    for (int u = 0; u < v; u++)
    {
      if (visited[u] == true)
      {
      }
      else if (dis[u] == 0)
      {
      }
      else
      {
        min = dis[u];
        index = u;
        for (int p = u + 1; p < v; p++)
        {
          if (visited[p] == true)
          {
          }
          else if (dis[p] == 0)
          {
          }
          else
          {
            if (min > dis[p])
            {
              min = dis[p];
              index = p;
            }
          }
        }
        start = index;
        break;
      }
    }

    j++;
  }

  int pp = end;
  while (end != wp)
  {

    push(end);
    int p = parent[end];
    end = p;
  }
  int kp = wp;
  if (end == wp)
  {
    push(end);
  }

  cout << "\n";

  int g = dis[pp];
  for (int i = 0; i < 7; i++)
  {
    visited[i] = false;
  }
  return g;
}
void push(int s)
{
  top++;
  stack[top] = s;
}
void pop()
{
  int k = stack[top];
  cout << vertices[k] << "  ";
  top--;
}

int shortestpath1(int start, int end, int v)
{
  int wp = start;
  int j = 0;
  parent1[start] = 0;
  dis1[start] = 0;
  while (j < v)
  {
    visited1[start] = true;
    for (int i = 0; i < v; i++)
    {
      if (add1[start][i] > 0 && visited1[i] == false)
      {
        if (dis1[i] == 0)
        {
          dis1[i] = dis1[start] + add1[start][i];
          parent1[i] = start;
        }
        else
        {
          int t = dis1[start] + add1[start][i];
          if (t < dis1[i])
          {
            dis1[i] = t;
            parent1[i] = start;
          }
        }
      }
    }
    int min;
    int index;
    for (int u = 0; u < v; u++)
    {
      if (visited1[u] == true)
      {
      }
      else if (dis1[u] == 0)
      {
      }
      else
      {
        min = dis1[u];
        index = u;
        for (int p = u + 1; p < v; p++)
        {
          if (visited1[p] == true)
          {
          }
          else if (dis1[p] == 0)
          {
          }
          else
          {
            if (min > dis1[p])
            {
              min = dis1[p];
              index = p;
            }
          }
        }
        start = index;
        break;
      }
    }

    j++;
  }

  int pp = end;
  while (end != wp)
  {

    push1(end);
    int p = parent1[end];
    end = p;
  }
  int kp = wp;
  if (end == wp)
  {
    push1(end);
  }

  cout << "\n";

  int g = dis1[pp];
  for (int i = 0; i < 7; i++)
  {
    visited1[i] = false;
  }
  return g;
}
void push1(int s)
{
  top1++;
  stack1[top1] = s;
}
void pop1()
{
  int k = stack1[top1];
  cout << vertices[k] << "  ";
  top1--;
}

void path2(int pp)
{

  cout << "The shortest path to reach " << vertices[pp] << "  is \n";
  cout << "PATH -->  ";
  while (top1 != -1)
  {
    pop1();
  }
  cout << " \n and total time travel is " << dis1[pp] << " minutes" << endl << endl;
}

void path1(int pp)
{
  cout << "The shortest path to reach " << vertices[pp] << "  is " << endl;
  cout << "PATH->  ";
  while (top != -1)
  {
    pop();
  }
  cout << " \n and total distance  travel is " << dis[pp] << " km" << endl << endl;
}
