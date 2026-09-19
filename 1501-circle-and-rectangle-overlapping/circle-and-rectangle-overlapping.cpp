class Solution {
    double distance(int x1, int y1, int x2, int y2) {
    double dis = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    dis = sqrt(dis);
    return dis;
}
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // int s1=xCenter>>1+yCenter>>1-radius>>1;
    //     int Xn = max(x1, min(xCenter, x2));
    // int Yn = max(y1, min(xCenter, y2));
    int left = min(x1, x2);
int right = max(x1, x2);
int bottom = min(y1, y2);
int top = max(y1, y2);

int Xn = max(left, min(xCenter, right));
int Yn = max(bottom, min(yCenter, top));
    if(distance(Xn,Yn,xCenter,yCenter)<=radius){
        return true;
    }
    else return false;
        
        
    }
};


// class Solution {
//     double distance(int x1,int y1, int x2,int y2){
//         double dis=(x1-x2)<<1+(y1-y2)<<1;
//         dis*dis=dis;
//         return dis;
//     }
// public:
//     bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
//         if(xCenter<=x1){
//             if(xCenter+radius>=x1&& dis(xCenter,yCenter,x1,y2)<=radius ){
//                 return true;

//             }
//             else return false;

//         }
//         else{
//             if(xCenter-radius<=x2&& dis(xCenter,yCenter,x1,y2)<=radius)
//         }
        
//     }
// };