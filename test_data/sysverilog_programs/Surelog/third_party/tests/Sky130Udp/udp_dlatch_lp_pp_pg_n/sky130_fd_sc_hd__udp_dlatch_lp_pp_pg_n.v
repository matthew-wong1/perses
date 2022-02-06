/**
 * Copyright 2020 The SkyWater PDK Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

`ifndef SKY130_FD_SC_HD__UDP_DLATCH_LP_PP_PG_N_V
`define SKY130_FD_SC_HD__UDP_DLATCH_LP_PP_PG_N_V

/**
 * udp_dlatch$lP_pp$PG$N: D-latch, gated standard drive / active high
 *                        (Q output UDP)
 *
 * Verilog primitive definition.
 *
 * WARNING: This file is autogenerated, do not modify directly!
 */

`timescale 1ns / 1ps
`default_nettype none

`ifdef NO_PRIMITIVES
`include "./sky130_fd_sc_hd__udp_dlatch_lp_pp_pg_n.blackbox.v"
`else
primitive sky130_fd_sc_hd__udp_dlatch$lP_pp$PG$N (
    Q       ,
    D       ,
    GATE    ,
    NOTIFIER,
    VPWR    ,
    VGND
);

    output Q       ;
    input  D       ;
    input  GATE    ;
    input  NOTIFIER;
    input  VPWR    ;
    input  VGND    ;

    reg Q;

    table
     //          D           GATE NOTIFIER VPWR VGND : Qtn : Qtn+1
                 *            0      ?      1    0   :  ?  :   -    ;
                 ?           (?0)    ?      1    0   :  ?  :   -    ;
                 ?           (1x)    ?      1    0   :  ?  :   -    ;
                 0           (0x)    ?      1    0   :  0  :   0    ;
                 1           (0x)    ?      1    0   :  1  :   1    ;
                 0           (x1)    ?      1    0   :  ?  :   0    ;
                 1           (x1)    ?      1    0   :  ?  :   1    ;
                (?0)          1      ?      1    0   :  ?  :   0    ;
                (?1)          1      ?      1    0   :  ?  :   1    ;
                 0           (01)    ?      1    0   :  ?  :   0    ;
                 1           (01)    ?      1    0   :  ?  :   1    ;
                (?1)          x      ?      1    0   :  1  :   1    ; // Reducing pessimism.
                (?0)          x      ?      1    0   :  0  :   0    ;
        // ['IfDef(functional)', '']                 ?            ?      *      1    0   :  ?  :   -    ;
        // ['Else', '']                 ?            ?      *      1    0   :  ?  :   x    ;
        // ['EndIfDef(functional)', '']                 ?            ?      ?      *    ?   :  ?  :   x    ; // any change on vpwr
                 ?            ?      ?      ?    *   :  ?  :   x    ; // any change on vgnd
    endtable
endprimitive
`endif // NO_PRIMITIVES

`default_nettype wire
`endif  // SKY130_FD_SC_HD__UDP_DLATCH_LP_PP_PG_N_V
