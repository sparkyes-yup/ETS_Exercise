#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <string>
#include <vector>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
/*Q1:   Given inputs of x & y, 
        have equations: a = sqrt(x^2+y^2); 
                        b = a + a^2 + a^6 + y^3;
        Find the value of b.

*/
void find_b(){
    double x,y;
    cout << "Please enter 2 numbers separated by space: ";

    // input validation; make sure the inputs are real numbers.
    while(!(cin >> x >> y)){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Please Enter 2 valid numbers: ";
    }
    cout << "x is: " << x << ", y is: " << y << endl;

    // round up to 3 decimal place
    double a = std::ceil(sqrt(x*x + y*y)*1000)/1000.0;
    cout << "a is: " << std::setprecision(3) << std::fixed << a << endl;

    double b = a + pow(a,2) + pow(a,6) + pow(y,3);

    // Final Result:
    cout << "The value of b is: " << std::setprecision(3) << std::fixed << b << endl;
}


/*
    Q2:  Create a code segment that will safely create and use a local variable on the stack.
*/
void local_stack_variable(){
    int a = 10;
    cout << "a is the local variable on the stack and a's value is: " << a << endl;
}

/*
    Q3: Create a code segment that will safely create and use a local variable on the heap.
*/

void local_heap_varialbe(){
    string *str = new string("hello");
    cout << "*str pointer is a local variable and it points to the string object stored on the heap, the str is: " << *str << endl;
    delete str; 
}

/*
    Q4: Create a 2D array on the heap;
*/
void array_2D(int row, int col, int ini){
    int **arr_2d = new int *[row];
    for(int i=0;i<row;i++){
        arr_2d[i] = new int[col];
        // initialize the arr with given input
        for(int j=0;j<col;j++){
            arr_2d[i][j]=ini;
            cout <<  arr_2d[i][j] << ", ";
        }
        cout << endl;
    }

    //free memory
    for(int i=0;i<row;i++){
        delete arr_2d[i];
    }
    delete[] arr_2d;
}


/*
    Q5: Convert the equation: S = sum(from i = 1 to N) of sum(from j = i+1 to N) of ai*aj/(N*(N-1)/2);
    	Why did i chose to code this way?
        A: Because the sum of sum looks like nested for loop; we only need to calculate each expression and sum them together.  
*/

    double vec_2sum(vector<int> vec){
    double sum = 0;
    // find the size of array, which is the N in the equation. Be careful: a1 is the position at a[0]!!!
    int N = vec.size();
    cout << "N is: " << N << endl;
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            sum += (double)vec.at(i-1)*vec.at(j-1)/(N*(N-1)/2);
        }
    }
    cout << "sum of sum is: " << sum << endl;
    return sum;
}



/*
    Q6: Write a code segment to generate the numbers between 100 and 200
        following the sequence 100, 100.03, 100.06, 100.09, … (i.e. each number is 0.03 greater than the last).
*/
void num_100_200_P03(){
    double num = 100;
    double top_bound = 200-0.03;

    // print the numbers 
    cout << "numbers between 100 and 200 are: " << num;
    while(num<=top_bound){
        num += 0.03;
        cout << ", " << num;
    }
}





/*
    Q7: Define an object-oriented class structure that would be capable of producing the following output consisting of a variety  of shapes.
*/

class Shape{

public: 
	string name;
	int vertices;
	vector<vector<double>> vertices_positions;
	double border_width;
	string border_color;
	string shape_color;
	int layer_level;
	
	// Constructor:
	Shape(string shape_name, int vs, vector<vector<double>> vsp, double bw, string bc, string sc, int ll){
		name = shape_name;
		vertices = vs;
		vertices_positions = vsp;
		border_width = bw;
		border_color = bc;
		shape_color = sc;
		layer_level = ll;
	}

	//draw shape
    bool drawshape();
	
};






/*
    Q8: Provide all possible permutations of a range of N numbers;
    // Using recursive
*/

// Q8-Helper function
vector<vector<int>> permutations(vector<vector<int>> vec){
    int size = vec.at(0).size();
    // when there is empty
	if(size==0)
		return vector<vector<int>>();
    // when there is 1 number   
	if(size==1)
		return vec;

    // when there is more than 2 numbers, we need to break the vector to 2 part, fix the first number, then check the remain numbers.
	// create an empty vector to store the return vector
    vector<vector<int>> vec_return;

    // Iterate the input vector(0) // for n=4; then i=0,1,2,3;
    for(int i = 0;i<size;i++){
 
        // then declare the remained vector in the from vector[0][i+1] to vector[0][n-1];
        vector<vector<int>> remain_vec;
        vector<int> temp_vec;
        for(int j=0;j<i;j++){
            temp_vec.push_back(vec[0][j]);
        }
        for(int j=i+1;j<size;j++){
            temp_vec.push_back(vec[0][j]);
        }
        remain_vec.push_back(temp_vec);
        // adding the remained vectors to the vec_return;
        for(auto rec_head: permutations(remain_vec)){
            // create the temporary head vector to store each vector from vector.at(0) to vector.at(n-1)
            vector<int> head;
            head.push_back(vec[0][i]);
            head.insert(std::end(head),std::begin(rec_head),std::end(rec_head));
            vec_return.push_back(head);
        }
        
    }
    return vec_return;
}

// Q8 function:
vector<vector<int>> find_permutations(int n){
    vector<vector<int>> vec ;
    vector<int> sub_vec;
    for(int i=1;i<=n;i++)
         sub_vec.push_back(i);
    vec.push_back(sub_vec);

    vector<vector<int>> per = permutations(vec);
    for(auto row: per){
        string separator;
        cout << "[";
        for(auto list: row){
            cout <<  separator <<  list;
            separator = ", ";
        }
        cout << "]" << endl;
    }
    return per;

}




int main(int argc, char *argv[]){

    cout << "\nQ1: \n";
    find_b();   //call find_b() to get value of b.

    cout << "\nQ2: \n";
    local_stack_variable(); // safely create and use a local variable on the stack
    cout << "\nQ3: \n";
    local_heap_varialbe();   // safely create and use a local variable on the heap
    cout << "\nQ4: \n";
    array_2D(2,3,9);            // Create a 2D array on the heap
    cout << "\nQ5: \n";
    vector<int> vec {1,2,3};     
    vec_2sum(vec);              //  sum of sum equation.
    cout << "\nQ6: \n";
    num_100_200_P03();              //  generate the numbers between 100 and 200, increased by 0.03;
   

   cout << "\nQ8: \n";
    int n =3;
    find_permutations(n);           // Q8 find all the permutation with given input integer n.
    

    return 0;

}