#include <bits/stdc++.h>
using namespace std;
#define lli long long
//#define int long long
inline void _QuickStreamOpen(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
const bool _QuickStream=true;
const bool _FILE=false;
const signed _TEST=0;
//------------------------------------------
bool amap[21][21]; 

int BlockWriteBeginPos[27][2]={
{0,0},

{17,19},{13,19},{9,19},
{12,17},{16,17},{20,17},

{17,15},{13,15},{9,15},
{12,13},{16,13},{20,13},

{17,11},{13,11},{9,11},    //C1  ~ C15

{4,11},{0,11},{3,9},{8,9}, //C16 ~ C19

{12,9},{16,9},{20,9},      //C20 ~ C22

{9,7},{12,4},{9,2},{12,0}//C23 ~ C26
};
int BlockWriteType[27]={ //0 Up | 1 Down | 16 19
0 , 0,0,0,1,1,1,0,0,0,1,1,1,0,0,0 , 16,0,1,19 , 1,1,1,0,1,0,1
//| C1                        C15 | C16   C19 | C20       C26|
};

int BlockWriteMove[4][8][2]={
{{0,0},{0,1},{1,0},{1,1},{2,0},{2,1},{3,0},{3,1}},//0 Up
{{0,0},{0,1},{-1,0},{-1,1},{-2,0},{-2,1},{-3,0},{-3,1}},//1 Down
{{0,0},{0,1},{1,0},{1,1},{3,0},{3,1},{4,0},{4,1}},//16
{{0,0},{0,1},{-1,0},{-1,1},{-3,0},{-3,1},{-4,0},{-4,1}}//19
};


void QR_WriteBlock(int no,int num){
	int bx=BlockWriteBeginPos[no][0],by=BlockWriteBeginPos[no][1];
	int t;
	if(no==16){t=2;}
	else if(no==19){t=3;}
	else{t=BlockWriteType[no];}
	
	for(int i=0;i<8;i++){
		int nx=bx+BlockWriteMove[t][i][0],ny=by+BlockWriteMove[t][i][1];
		amap[nx][ny]=(num%2)^((nx+ny)%2==0?1:0);
		
		num>>=1;
	}
}

void QR_WriteLine(int line,string text){
	for(int i=0;i<21;i++){
		amap[line][i]=(text[i]=='#'?1:0);
	}
}

void QR_init(){
	QR_WriteLine(0,"#######.#.#.#.#######");
	QR_WriteLine(1,"#.....#...###.#.....#");
	QR_WriteLine(2,"#.###.#...#...#.###.#");
	QR_WriteLine(3,"#.###.#.##.#..#.###.#");
	QR_WriteLine(4,"#.###.#..#.##.#.###.#");
	QR_WriteLine(5,"#.....#....##.#.....#");
	QR_WriteLine(6,"#######.#.#.#.#######");
	QR_WriteLine(7,"...........##........");
	QR_WriteLine(8,"..#.###.##...#...#..#");
	QR_WriteLine(9,".#.#...#.........####");
	QR_WriteLine(10,".#...##..###..#.#.#.#");
	QR_WriteLine(11,"..#.#...##.#.##..#..#");
	QR_WriteLine(12,".#.#.####.###.#.#.###");
	QR_WriteLine(13,"........#.#...##.###.");
	QR_WriteLine(14,"#######...#....#..#..");
	QR_WriteLine(15,"#.....#.#.###..###...");
	QR_WriteLine(16,"#.###.#.#..#..##..#.#");
	QR_WriteLine(17,"#.###.#..##.##....##.");
	QR_WriteLine(18,"#.###.#.##....#.#...#");
	QR_WriteLine(19,"#.....#...#.#.....#..");
	QR_WriteLine(20,"#######..#..#...#.#.#");
}

void QR_Print(){
	for(int i=0;i<21;i++){
		for(int j=0;j<21;j++){
			cout<<(amap[i][j]?'#':'.');
		}cout<<"\n";
	}
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}
	
	QR_init();
	//QR_Print();cout<<"\n----------------------\n";
	for(int i=1;i<=26;i++){
		int cget;cin>>cget;QR_WriteBlock(i,cget);
	}
	QR_Print();

	return 0;
}

