module matmul(A,B,y,clk);    
    input logic [31:0] A;
    input logic [31:0] B;
    output logic [31:0] y;
	 input logic clk;
   
    logic [7:0] A1 [0:1][0:1];
    logic [7:0] B1 [0:1][0:1];
    logic [7:0] y1 [0:1][0:1]; 
    integer i,j,k;

	 // check for max freq 
	 // initialize matrix values in BRAM
	 
    always @(posedge clk) // add a clock
    begin
        {A1[0][0],A1[0][1],A1[1][0],A1[1][1]} = A;
        {B1[0][0],B1[0][1],B1[1][0],B1[1][1]} = B;
        i = 0;
        j = 0;
        k = 0;
        {y1[0][0],y1[0][1],y1[1][0],y1[1][1]} = 32'd0; 
        for(i=0;i < 2;i=i+1)
            for(j=0;j < 2;j=j+1)
                for(k=0;k < 2;k=k+1)
                    y1[i][j] = y1[i][j] + (A1[i][k] * B1[k][j]);
         
        y = {y1[0][0],y1[0][1],y1[1][0],y1[1][1]};            
    end 
endmodule
