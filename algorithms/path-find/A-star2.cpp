// A* path finding
// The goal is to find the best path by always 
// trying the most promising step first

// A C++ Program to implement A* Search Algorithm 
#include <cstdio>
#include <cmath>
#include <cfloat>
#include <utility>
#include <stack>
#include <set>

namespace {
struct CellIndex;
struct Cell;
struct PrioritizedCell;
}

constexpr int n_rows = 9;
constexpr int n_cols = 10;

using Pair = std::pair<int,int>;
using Grid = int [n_rows][n_cols];
using CellDetails = Cell[n_rows][n_cols];


namespace {
struct CellIndex{
    int row,col;

    std::pair<int,int> asPair() const { return {row,col}; }

    friend bool operator==(const CellIndex &a, const CellIndex &b)
    {
        return a.asPair() == b.asPair();
    }

    friend bool operator!=(const CellIndex &a, const CellIndex &b)
    {
        return !(a==b);
    }

    friend bool operator<(const CellIndex &a, const CellIndex &b)
    {
        return a.asPair() < b.asPair();
    }
};
}


namespace {
struct PrioritizedCell {
    double priority;
    CellIndex cell_index;

    std::pair<double, CellIndex> asPair() const { return {priority, cell_index}; }

    PrioritizedCell(double priority, CellIndex cell_index)
    : priority(priority),
      cell_index(cell_index)
    {
    }

    friend bool operator<(const PrioritizedCell &a, const PrioritizedCell &b)
    {
        return a.asPair() < b.asPair();
    }
};    
}


namespace {
struct Direction {
    int row_offset;
    int col_offset;
};
}


// A structure to hold the neccesary parameters 
namespace {
struct Cell 
{ 
    CellIndex parent = {-1,-1};
	    // Row and Column index of its parent 
	    // Note that 0 <= i <= n_rows-1 & 0 <= j <= n_cols-1

    double g = FLT_MAX;  // g = cost to source
	double f = FLT_MAX;  // g + heuristic cost to dest
}; 
}

// A Utility Function to check whether given cell (row, col) 
// is a valid cell or not. 
static bool isValid(CellIndex ci)
{
    int row = ci.row;
    int col = ci.col;
	return (row >= 0) && (row < n_rows) && (col >= 0) && (col < n_cols); 
}


static bool isBlocked(const Grid &grid, CellIndex s)
{
    return (grid[s.row][s.col] == 0);
}


// A Utility Function to calculate the 'h' heuristics. 
static double calculateHValue(CellIndex from, CellIndex dest) 
{ 
	// Return using the distance formula
    double drow = from.row - dest.row;
    double dcol = from.col - dest.col;
	return sqrt(drow*drow + dcol*dcol);
} 


static CellIndex parentCell(CellIndex c, const CellDetails &cellDetails)
{
    return cellDetails[c.row][c.col].parent;
}


// A Utility Function to trace the path from the source 
// to destination 
static void tracePath(const CellDetails &cellDetails, CellIndex dest) 
{ 
	printf ("\nThe Path is "); 
	std::stack<CellIndex> path; 

	while (parentCell(dest, cellDetails) != dest)
	{ 
		path.push(dest);
        dest = parentCell(dest, cellDetails);
	} 

	path.push(dest);

	while (!path.empty()) 
	{ 
		CellIndex p = path.top(); 
		path.pop(); 
		printf("-> (%d,%d) ",p.row,p.col); 
	} 

	return; 
} 


namespace {
struct Searcher {
    const Grid &grid;
    const CellIndex dest;

	bool closedList[n_rows][n_cols] = {};
        // Create a closed list and initialise it to false which means 
        // that no cell has been included yet 
        // This closed list is implemented as a boolean 2D array 

	CellDetails cellDetails; 
	    // Declare a 2D array of structure to hold the details 
	    // of that cell 

	std::set<PrioritizedCell> openList; 
        // Create an open list having information as- 
        // <f, <i, j>> 
        // where f = g + h, 
        // and i, j are the row and column index of that cell 
        // Note that 0 <= i <= n_rows-1 & 0 <= j <= n_cols-1 
        // This open list is implenented as a set of pair of pair.*/

    Searcher(const Grid &grid, CellIndex dest)
    : grid(grid), dest(dest)
    {
    }

    Cell &cell(CellIndex c)
    {
        return cellDetails[c.row][c.col];
    }

    bool& isClosed(CellIndex c)
    {
        return closedList[c.row][c.col];
    }
};
}


static bool
trySucc(const CellIndex next_cell_index, Searcher &searcher, const CellIndex current_cell_index)
{
    const CellIndex dest = searcher.dest;
	auto &openList  = searcher.openList;
    const Grid &grid = searcher.grid;

    if (!isValid(next_cell_index))
    {
        return false;
    }

    if (next_cell_index == dest) {
        // Set the Parent of the destination cell 
        searcher.cell(next_cell_index).parent = current_cell_index;
        return true; 
    }

    if (searcher.isClosed(next_cell_index) || isBlocked(grid, next_cell_index)) 
    {
       return false;
    }

    Cell &succ = searcher.cell(next_cell_index);
    double new_g = searcher.cell(current_cell_index).g + 1.0; 
    double new_h = calculateHValue(next_cell_index, dest); 
    double new_f = new_g + new_h; 

    if (succ.f == FLT_MAX ||  succ.f > new_f) 
    { 
        openList.insert({new_f,  next_cell_index}); 

        // Update the details of this cell 
        succ.f = new_f; 
        succ.g = new_g; 
        succ.parent = current_cell_index;
    } 

    return false;
}

/*
//   	N.W    N    N.E
//   	   \   |   /
//   	    \  |  /
//   	W----Cell----E
//          /  |  \
//         /   |   \
//   	S.W    S    S.E
*/

static const Direction directions[] = {
    {-1, 0 },  // North
    { 1, 0 },  // South
    { 0, 1 },  // East
    { 0,-1 },  // West
    {-1, 1 },  // North-East
    {-1,-1 },  // North-West
    { 1, 1 },  // South-East
    { 1,-1 },  // South-West
};


// A Function to find the shortest path between 
// a given source cell to a destination cell according 
// to A* Search Algorithm 
static void aStarSearch(const Grid &grid, Pair src_pair, Pair dest_pair) 
{ 
    CellIndex src = {src_pair.first, src_pair.second};
    CellIndex dest = {dest_pair.first, dest_pair.second};

	// If the source is out of range 
	if (!isValid(src)) 
	{ 
		printf ("Source is invalid\n"); 
		return; 
	} 

	// If the destination is out of range 
	if (!isValid(dest)) 
	{ 
		printf ("Destination is invalid\n"); 
		return; 
	} 

	// Either the source or the destination is blocked 
	if (isBlocked(grid, src) ||  isBlocked(grid, dest)) 
	{ 
		printf ("Source or the destination is blocked\n"); 
		return; 
	} 

    CellIndex current_cell_index = src;

	// If the destination cell is the same as source cell 
	if (current_cell_index == dest)
	{ 
		printf ("We are already at the destination\n"); 
		return; 
	}

    Searcher searcher(grid, dest);
	CellDetails &cellDetails = searcher.cellDetails;

	// Initialising the parameters of the starting node
    {
        Cell &start = searcher.cell(current_cell_index);
        start.f = 0.0; 
        start.g = 0.0; 
        start.parent = current_cell_index;     
    }

	auto &openList = searcher.openList;

	// Put the starting cell on the open list and set its 
	// 'f' as 0 
	openList.insert({0.0, current_cell_index});

	while (!openList.empty()) 
	{ 
		// Remove the highest-priority cell from the open list.
		PrioritizedCell p = *openList.begin(); 
		openList.erase(openList.begin()); 
        current_cell_index = p.cell_index;
        searcher.isClosed(current_cell_index) = true;
	
        for (auto &d : directions) {
            CellIndex s = {
                current_cell_index.row + d.row_offset,
                current_cell_index.col + d.col_offset
            };

            if (trySucc( s, searcher, current_cell_index )) {
                printf ("The destination cell is found\n"); 
                tracePath(cellDetails, dest);
                return;
            }
        }
	} 

	// When the destination cell is not found and the open 
	// list is empty, then we conclude that we failed to 
	// reach the destiantion cell. This may happen when the 
	// there is no way to destination cell (due to blockages) 
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
	{ 
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
		{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 }, 
		{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 }, 
		{ 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 }, 
		{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 }, 
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }, 
		{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 }, 
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
		{ 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 } 
	}; 

	// Source is the left-most bottom-most corner 
    Pair src(8, 0); 

	// Destination is the left-most top-most corner 
	Pair dest(0, 0); 

	aStarSearch(grid, src, dest); 

	return(0); 
}
