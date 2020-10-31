// A* path finding
// The goal is to find the best path by always 
// trying the most promising step first
/* Special Thanks to Vaughn to make codes prettier
* Improve const usage
* Remove comparison to true and false
* reduce i, j scope
* introduce cell_index data structure
*/

// A C++ Program to implement A* Search Algorithm 
#include <utility>
#include <cmath>
#include <cstdio>
#include <stack>
#include <cstring>
#include <cfloat>
#include <set>
#include <array>

using std::pair;
using std::stack;
using std::make_pair;
using std::set;

constexpr int ROW = 9;
constexpr int COL = 10;

// Creating a shortcut for int, int pair type
using Pair = pair<int,int>;

// Creating a shortcut for pair<int, pair<int, int>> type 
using pPair = pair<double, pair<int,int>>;

//using Grid = int [ROW][COL];

using Grid = std::array<std::array<int,COL>,ROW>;

namespace {
struct cell_index {
    int i,j;

    friend bool operator==(const cell_index &a, const cell_index &b)
    {
        return a.i == b.i && a.j == b.j;
    }

    friend bool operator!=(const cell_index &a, const cell_index &b)
    {
        return !(a==b);
    }
};
}


// A structure to hold the neccesary parameters 
namespace {
struct cell 
{ 
	// Row and Column index of its parent 
	// Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
    cell_index parent;
	// f = g + h 
	double f, g, h; 
}; 
}

// A Utility Function to check whether given cell (row, col) 
// is a valid cell or not. 
static bool isValid(int row, int col) 
{ 
	// Returns true if row number and column number 
	// is in range 
	return (row >= 0) && (row < ROW) && 
		(col >= 0) && (col < COL); 
} 

// A Utility Function to check whether the given cell is 
// blocked or not 
static bool isUnBlocked(const Grid &grid, int row, int col) 
{ 
	return (grid[row][col] == 1);
} 

// A Utility Function to check whether destination cell has 
// been reached or not 
static bool isDestination(int row, int col, Pair dest) 
{ 
	return (row == dest.first && col == dest.second) ;
} 

// A Utility Function to calculate the 'h' heuristics. 
static double calculateHValue(int row, int col, Pair dest) 
{ 
	// Return using the distance formula
    double dx = row-dest.first;
    double dy = col-dest.second;
	return sqrt(dx*dx + dy*dy);
} 

// A Utility Function to trace the path from the source 
// to destination 
static void tracePath(const cell (&cellDetails)[ROW][COL], Pair dest) 
{ 
	printf ("\nThe Path is "); 
    cell_index ci = {dest.first, dest.second};

	stack<Pair> Path; 

	while (cellDetails[ci.i][ci.j].parent != ci)
	{ 
		Path.push (make_pair (ci.i, ci.j)); 
        ci = cellDetails[ci.i][ci.j].parent;
	} 

	Path.push (make_pair (ci.i, ci.j)); 
	while (!Path.empty()) 
	{ 
		pair<int,int> p = Path.top(); 
		Path.pop(); 
		printf("-> (%d,%d) ",p.first,p.second); 
	} 

	return; 
} 

// A Function to find the shortest path between 
// a given source cell to a destination cell according 
// to A* Search Algorithm 
static void aStarSearch(const Grid &grid, Pair src, Pair dest) 
{ 
	// If the source is out of range 
	if (isValid (src.first, src.second) == false) 
	{ 
		printf ("Source is invalid\n"); 
		return; 
	} 

	// If the destination is out of range 
	if (!isValid (dest.first, dest.second)) 
	{ 
		printf ("Destination is invalid\n"); 
		return; 
	} 

	// Either the source or the destination is blocked 
	if (!isUnBlocked(grid, src.first, src.second) || 
			!isUnBlocked(grid, dest.first, dest.second)) 
	{ 
		printf ("Source or the destination is blocked\n"); 
		return; 
	} 

	// If the destination cell is the same as source cell 
	if (isDestination(src.first, src.second, dest)) 
	{ 
		printf ("We are already at the destination\n"); 
		return; 
	} 

	// Create a closed list and initialise it to false which means 
	// that no cell has been included yet 
	// This closed list is implemented as a boolean 2D array 
	bool closedList[ROW][COL]; 
	memset(closedList, false, sizeof (closedList)); 

	// Declare a 2D array of structure to hold the details 
	//of that cell 
	cell cellDetails[ROW][COL]; 

	for (int i=0; i<ROW; i++) 
	{ 
		for (int j=0; j<COL; j++) 
		{ 
			cellDetails[i][j].f = FLT_MAX; 
			cellDetails[i][j].g = FLT_MAX; 
			cellDetails[i][j].h = FLT_MAX; 
			cellDetails[i][j].parent = {-1,-1};
		} 
	} 


	// Initialising the parameters of the starting node 
	int i = src.first;
    int j = src.second; 
	cellDetails[i][j].f = 0.0; 
	cellDetails[i][j].g = 0.0; 
	cellDetails[i][j].h = 0.0; 
	cellDetails[i][j].parent = {i,j}; 

	/* 
	Create an open list having information as- 
	<f, <i, j>> 
	where f = g + h, 
	and i, j are the row and column index of that cell 
	Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1 
	This open list is implenented as a set of pair of pair.*/
	set<pPair> openList; 

	// Put the starting cell on the open list and set its 
	// 'f' as 0 
	openList.insert(make_pair (0.0, make_pair (i, j))); 

	// We set this boolean value as false as initially 
	// the destination is not reached. 
	bool foundDest = false; 

	while (!openList.empty()) 
	{ 
		pPair p = *openList.begin(); 

		// Remove this vertex from the open list 
		openList.erase(openList.begin()); 

		// Add this vertex to the closed list 
		i = p.second.first; 
		j = p.second.second; 
		closedList[i][j] = true; 
	
	/* 
		Generating all the 8 successor of this cell 

			N.W N N.E 
			\ | / 
			\ | / 
			W----Cell----E 
				/ | \ 
			/ | \ 
			S.W S S.E 

		Cell-->Popped Cell (i, j) 
		N --> North	 (i-1, j) 
		S --> South	 (i+1, j) 
		E --> East	 (i, j+1) 
		W --> West		 (i, j-1) 
		N.E--> North-East (i-1, j+1) 
		N.W--> North-West (i-1, j-1) 
		S.E--> South-East (i+1, j+1) 
		S.W--> South-West (i+1, j-1)*/

		// To store the 'g', 'h' and 'f' of the 8 successors 
		double gNew, hNew, fNew; 

		//----------- 1st Successor (North) ------------ 

		// Only process this cell if this is a valid one 
		if (isValid(i-1, j)) 
		{ 
			// If the destination cell is the same as the 
			// current successor 
			if (isDestination(i-1, j, dest)) 
			{ 
				// Set the Parent of the destination cell 
				cellDetails[i-1][j].parent = {i,j}; 
				printf ("The destination cell is found\n"); 
				tracePath (cellDetails, dest); 
				foundDest = true; 
				return; 
			} 
			// If the successor is already on the closed 
			// list or if it is blocked, then ignore it. 
			// Else do the following 
			else if (!closedList[i-1][j] && isUnBlocked(grid, i-1, j)) 
			{ 
				gNew = cellDetails[i][j].g + 1.0; 
				hNew = calculateHValue (i-1, j, dest); 
				fNew = gNew + hNew; 

				// If it isn’t on the open list, add it to 
				// the open list. Make the current square 
				// the parent of this square. Record the 
				// f, g, and h costs of the square cell 
				//			 OR 
				// If it is on the open list already, check 
				// to see if this path to that square is better, 
				// using 'f' cost as the measure. 
				if (cellDetails[i-1][j].f == FLT_MAX || 
						cellDetails[i-1][j].f > fNew) 
				{ 
					openList.insert( make_pair(fNew, 
											make_pair(i-1, j))); 

					// Update the details of this cell 
					cellDetails[i-1][j].f = fNew; 
					cellDetails[i-1][j].g = gNew; 
					cellDetails[i-1][j].h = hNew; 
					cellDetails[i-1][j].parent = {i,j};
				} 
			} 
		} 

		//----------- 2nd Successor (South) ------------ 

		// Only process this cell if this is a valid one 
		if (isValid(i+1, j)) 
		{ 
			// If the destination cell is the same as the 
			// current successor 
			if (isDestination(i+1, j, dest) == true) 
			{ 
				// Set the Parent of the destination cell 
				cellDetails[i+1][j].parent = {i,j};
				printf("The destination cell is found\n"); 
				tracePath(cellDetails, dest); 
				foundDest = true; 
				return; 
			} 
			// If the successor is already on the closed 
			// list or if it is blocked, then ignore it. 
			// Else do the following 
			else if (!closedList[i+1][j] && 
					isUnBlocked(grid, i+1, j)) 
			{ 
				gNew = cellDetails[i][j].g + 1.0; 
				hNew = calculateHValue(i+1, j, dest); 
				fNew = gNew + hNew; 

				// If it isn’t on the open list, add it to 
				// the open list. Make the current square 
				// the parent of this square. Record the 
				// f, g, and h costs of the square cell 
				//			 OR 
				// If it is on the open list already, check 
				// to see if this path to that square is better, 
				// using 'f' cost as the measure. 
				if (cellDetails[i+1][j].f == FLT_MAX || 
						cellDetails[i+1][j].f > fNew) 
				{ 
					openList.insert( make_pair (fNew, make_pair (i+1, j))); 
					// Update the details of this cell 
					cellDetails[i+1][j].f = fNew; 
					cellDetails[i+1][j].g = gNew; 
					cellDetails[i+1][j].h = hNew; 
					cellDetails[i+1][j].parent = {i,j};
				} 
			} 
		} 

		//----------- 3rd Successor (East) ------------ 

		// Only process this cell if this is a valid one 
		if (isValid (i, j+1)) 
		{ 
			// If the destination cell is the same as the 
			// current successor 
			if (isDestination(i, j+1, dest)) 
			{ 
				// Set the Parent of the destination cell 
				cellDetails[i][j+1].parent = {i,j};
				printf("The destination cell is found\n"); 
				tracePath(cellDetails, dest); 
				foundDest = true; 
				return; 
			} 

			// If the successor is already on the closed 
			// list or if it is blocked, then ignore it. 
			// Else do the following 
			else if (!closedList[i][j+1] && isUnBlocked (grid, i, j+1)) 
			{ 
				gNew = cellDetails[i][j].g + 1.0; 
				hNew = calculateHValue (i, j+1, dest); 
				fNew = gNew + hNew; 

				// If it isn’t on the open list, add it to 
				// the open list. Make the current square 
				// the parent of this square. Record the 
				// f, g, and h costs of the square cell 
				//			 OR 
				// If it is on the open list already, check 
				// to see if this path to that square is better, 
				// using 'f' cost as the measure. 
				if (cellDetails[i][j+1].f == FLT_MAX || 
						cellDetails[i][j+1].f > fNew) 
				{ 
					openList.insert( make_pair(fNew, 
										make_pair (i, j+1))); 

					// Update the details of this cell 
					cellDetails[i][j+1].f = fNew; 
					cellDetails[i][j+1].g = gNew; 
					cellDetails[i][j+1].h = hNew; 
					cellDetails[i][j+1].parent = {i,j};
				} 
			} 
		} 

		//----------- 4th Successor (West) ------------ 

		// Only process this cell if this is a valid one 
		if (isValid(i, j-1)) 
		{ 
			// If the destination cell is the same as the 
			// current successor 
			if (isDestination(i, j-1, dest)) 
			{ 
				// Set the Parent of the destination cell 
				cellDetails[i][j-1].parent = {i,j};
				printf("The destination cell is found\n"); 
				tracePath(cellDetails, dest); 
				foundDest = true; 
				return; 
			} 

			// If the successor is already on the closed 
			// list or if it is blocked, then ignore it. 
			// Else do the following 
			else if (!closedList[i][j-1] && isUnBlocked(grid, i, j-1)) 
			{ 
				gNew = cellDetails[i][j].g + 1.0; 
				hNew = calculateHValue(i, j-1, dest); 
				fNew = gNew + hNew; 

				// If it isn’t on the open list, add it to 
				// the open list. Make the current square 
				// the parent of this square. Record the 
				// f, g, and h costs of the square cell 
				//			 OR 
				// If it is on the open list already, check 
				// to see if this path to that square is better, 
				// using 'f' cost as the measure. 
				if (cellDetails[i][j-1].f == FLT_MAX || 
						cellDetails[i][j-1].f > fNew) 
				{ 
					openList.insert( make_pair (fNew, 
										make_pair (i, j-1))); 

					// Update the details of this cell 
					cellDetails[i][j-1].f = fNew; 
					cellDetails[i][j-1].g = gNew; 
					cellDetails[i][j-1].h = hNew; 
					cellDetails[i][j-1].parent = {i,j};
				} 
			} 
		} 

		//----------- 5th Successor (North-East) ------------ 

		// Only process this cell if this is a valid one 
		if (isValid(i-1, j+1)) 
		{ 
			// If the destination cell is the same as the 
			// current successor 
			if (isDestination(i-1, j+1, dest)) 
			{ 
				// Set the Parent of the destination cell 
				cellDetails[i-1][j+1].parent = {i,j};
				printf ("The destination cell is found\n"); 
				tracePath (cellDetails, dest); 
				foundDest = true; 
				return; 
			} 

			// If the successor is already on the closed 
			// list or if it is blocked, then ignore it. 
			// Else do the following 
			else if (!closedList[i-1][j+1] && isUnBlocked(grid, i-1, j+1)) 
			{ 
				gNew = cellDetails[i][j].g + 1.414; 
				hNew = calculateHValue(i-1, j+1, dest); 
				fNew = gNew + hNew; 

				// If it isn’t on the open list, add it to 
				// the open list. Make the current square 
				// the parent of this square. Record the 
				// f, g, and h costs of the square cell 
				//			 OR 
				// If it is on the open list already, check 
				// to see if this path to that square is better, 
				// using 'f' cost as the measure. 
				if (cellDetails[i-1][j+1].f == FLT_MAX || 
						cellDetails[i-1][j+1].f > fNew) 
				{ 
					openList.insert( make_pair (fNew, 
									make_pair(i-1, j+1))); 

					// Update the details of this cell 
					cellDetails[i-1][j+1].f = fNew; 
					cellDetails[i-1][j+1].g = gNew; 
					cellDetails[i-1][j+1].h = hNew; 
					cellDetails[i-1][j+1].parent = {i,j};
				} 
			} 
		} 

		//----------- 6th Successor (North-West) ------------ 

		// Only process this cell if this is a valid one 
		if (isValid (i-1, j-1)) 
		{ 
			// If the destination cell is the same as the 
			// current successor 
			if (isDestination (i-1, j-1, dest)) 
			{ 
				// Set the Parent of the destination cell 
				cellDetails[i-1][j-1].parent = {i,j};
				printf ("The destination cell is found\n"); 
				tracePath (cellDetails, dest); 
				foundDest = true; 
				return; 
			} 

			// If the successor is already on the closed 
			// list or if it is blocked, then ignore it. 
			// Else do the following 
			else if (!closedList[i-1][j-1] && 
					isUnBlocked(grid, i-1, j-1)) 
			{ 
				gNew = cellDetails[i][j].g + 1.414; 
				hNew = calculateHValue(i-1, j-1, dest); 
				fNew = gNew + hNew; 

				// If it isn’t on the open list, add it to 
				// the open list. Make the current square 
				// the parent of this square. Record the 
				// f, g, and h costs of the square cell 
				//			 OR 
				// If it is on the open list already, check 
				// to see if this path to that square is better, 
				// using 'f' cost as the measure. 
				if (cellDetails[i-1][j-1].f == FLT_MAX || 
						cellDetails[i-1][j-1].f > fNew) 
				{ 
					openList.insert( make_pair (fNew, make_pair (i-1, j-1))); 
					// Update the details of this cell 
					cellDetails[i-1][j-1].f = fNew; 
					cellDetails[i-1][j-1].g = gNew; 
					cellDetails[i-1][j-1].h = hNew; 
					cellDetails[i-1][j-1].parent = {i,j};
				} 
			} 
		} 

		//----------- 7th Successor (South-East) ------------ 

		// Only process this cell if this is a valid one 
		if (isValid(i+1, j+1)) 
		{ 
			// If the destination cell is the same as the 
			// current successor 
			if (isDestination(i+1, j+1, dest)) 
			{ 
				// Set the Parent of the destination cell 
				cellDetails[i+1][j+1].parent = {i,j};
				printf ("The destination cell is found\n"); 
				tracePath (cellDetails, dest); 
				foundDest = true; 
				return; 
			} 

			// If the successor is already on the closed 
			// list or if it is blocked, then ignore it. 
			// Else do the following 
			else if (!closedList[i+1][j+1] && isUnBlocked(grid, i+1, j+1)) 
			{ 
				gNew = cellDetails[i][j].g + 1.414; 
				hNew = calculateHValue(i+1, j+1, dest); 
				fNew = gNew + hNew; 

				// If it isn’t on the open list, add it to 
				// the open list. Make the current square 
				// the parent of this square. Record the 
				// f, g, and h costs of the square cell 
				//			 OR 
				// If it is on the open list already, check 
				// to see if this path to that square is better, 
				// using 'f' cost as the measure. 
				if (cellDetails[i+1][j+1].f == FLT_MAX || 
						cellDetails[i+1][j+1].f > fNew) 
				{ 
					openList.insert(make_pair(fNew, 
										make_pair (i+1, j+1))); 

					// Update the details of this cell 
					cellDetails[i+1][j+1].f = fNew; 
					cellDetails[i+1][j+1].g = gNew; 
					cellDetails[i+1][j+1].h = hNew; 
					cellDetails[i+1][j+1].parent = {i,j};
				} 
			} 
		} 

		//----------- 8th Successor (South-West) ------------ 

		// Only process this cell if this is a valid one 
		if (isValid (i+1, j-1)) 
		{ 
			// If the destination cell is the same as the 
			// current successor 
			if (isDestination(i+1, j-1, dest)) 
			{ 
				// Set the Parent of the destination cell 
				cellDetails[i+1][j-1].parent = {i,j};
				printf("The destination cell is found\n"); 
				tracePath(cellDetails, dest); 
				foundDest = true; 
				return; 
			} 

			// If the successor is already on the closed 
			// list or if it is blocked, then ignore it. 
			// Else do the following 
			else if (!closedList[i+1][j-1] && isUnBlocked(grid, i+1, j-1)) 
			{ 
				gNew = cellDetails[i][j].g + 1.414; 
				hNew = calculateHValue(i+1, j-1, dest); 
				fNew = gNew + hNew; 

				// If it isn’t on the open list, add it to 
				// the open list. Make the current square 
				// the parent of this square. Record the 
				// f, g, and h costs of the square cell 
				//			 OR 
				// If it is on the open list already, check 
				// to see if this path to that square is better, 
				// using 'f' cost as the measure. 
				if (cellDetails[i+1][j-1].f == FLT_MAX || 
						cellDetails[i+1][j-1].f > fNew) 
				{ 
					openList.insert(make_pair(fNew, 
										make_pair(i+1, j-1))); 

					// Update the details of this cell 
					cellDetails[i+1][j-1].f = fNew; 
					cellDetails[i+1][j-1].g = gNew; 
					cellDetails[i+1][j-1].h = hNew; 
					cellDetails[i+1][j-1].parent = {i,j};
				} 
			} 
		} 
	} 

	// When the destination cell is not found and the open 
	// list is empty, then we conclude that we failed to 
	// reach the destiantion cell. This may happen when the 
	// there is no way to destination cell (due to blockages) 
	if (!foundDest) 
		printf("Failed to find the Destination Cell\n"); 

	return; 
} 


// Driver program to test above function 
int main() 
{ 
	/* Description of the Grid- 
	1--> The cell is not blocked 
	0--> The cell is blocked */
	const Grid grid = 
	{{ 
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
		{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 }, 
		{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 }, 
		{ 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 }, 
		{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 }, 
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }, 
		{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 }, 
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
		{ 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 } 
	}}; 

	// Source is the left-most bottom-most corner 
    Pair src = make_pair(8, 0); 

	// Destination is the left-most top-most corner 
	Pair dest = make_pair(0, 0); 

	aStarSearch(grid, src, dest); 

	return(0); 
}

