`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/04/2022 03:51:30 PM
// Design Name: 
// Module Name: main
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module main(
    input logic [7:0] a,
    input logic [7:0] b,
    input logic [2:0] co,
    output logic [15:0] q
    );
    int i=0;
    int j=0;

    logic [15:0]w= 16'b0;
    int vari = 0;
    
    always_comb begin
        if (co == 3'b001) begin
            vari = a;
            if (vari % 2 != 0) 
                q <= 1;
            else 
                q <= 0;
        end
        
        if (co == 3'b010) begin
            q <= a << 5;
        end
        
        if (co == 3'b011) begin
            q <= ((a*55) + b);
        end
        
        if (co == 3'b100) begin
            if (a > b)
                q <= b;
            else
                q <= a;
        end
        
        if (co == 3'b101) begin
            q = a+b;
            for(j=0;j<9;j++) begin
                w = q;
                q = q+w;
            end
        end 
    end
endmodule
