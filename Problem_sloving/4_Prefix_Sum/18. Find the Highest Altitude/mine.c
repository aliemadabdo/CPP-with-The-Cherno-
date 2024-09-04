int largestAltitude(int* gain, int gainSize) {
 /*Input: gain = [-5,1,5,0,-7]
Output: 1
Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.*/

    int altitude = 0, result = altitude;

    for(int i=0; i<gainSize; i++){
        altitude += gain[i];
        if(altitude > result){
            result = altitude;
        }
    }

    return result;
}