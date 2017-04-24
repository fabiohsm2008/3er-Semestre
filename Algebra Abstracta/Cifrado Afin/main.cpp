#include <iostream>
#include <string>
#include "Funciones.h"
#include "Cifrado.h"

using namespace std;

int main()
{
    string cadena_1 = "VknyCwkmkCugfygCneqgCtuhlylvkCfqfkCgehwkB";
    Cifrado a(29847,24);
    cadena_1 = a.decodificar(cadena_1);
    cout << "Mensaje descifrado = " << cadena_1 << endl;

    cout << endl;

    string cadena_2 = "WbmNFVJQ.xFV,bUbmV.JMVRFNMrVnbq.NnMNMxmVR,JQJ.nJqjVNUJMGVTUJBxRFVQbmMRVFRMMJ.VNqJFVRVnbFFb,bGVTUJBxRFVymJqjJUURVFRxmJ.VRnVyNmFNqMxFVQURnNmRMGVpxmRCJMxmVnbqiRUUJ.VNyyJnJMxmVFJGVzMVnbqjxNVMbmMbmVCURq,JMVNqJFVyRxnJCx.rVJ,VQmNMJxFVqJ.JVnbqjxNGVpUR..VRQMNqMVMRnJMJV.bnJb.BxVR,VUJMbmRVMbmBxNqMVQNmVnbqxCJRVqb.MmRrVQNmVJqnNQMb.VYJFNqRNb.GV;x.QNq,J..NVFRMMJ.VRnVyNUJ.VNxV.bUUJnJMx,JqGVLqVQmNMJxFVURnx.VRMVxUURFnbmQNmVJqMNm,xFGVSYR.NUUx.VjmRiJ,RVFJVFNMx.rVxMVmxMmxFVRxjxNViJiNmmRVNjNMGVabqNnVRxnMbmVMbmMbmVNjNMViNqNqRMJ.VQmNMJxFGVDxJ.BxNVJFQNm,JNMVUJjxURVRMVb,JbVnbFFb,bVnbFFb,bGVsxUURVFRUN.xR,RVNjN.MR.VmJ.x.rVFbUN.MJNVyRnJUJ.J.VbmnJVQxUiJqRmVJqGV;x.QNq,J..NVYNq,mNmJMV,xJV.NFrViNUVUxnMx.VFRxmJ.V.x.nJQJMVRGVabqNnVURbmNNMVMJqnJ,xqMVFRIJFx.GVSNUUNqMN.BxNVnbqiRUUJ.VbmnJVqJ.JrViNUVxUMmJnN.VqxqnV.nNUNmJ.BxNVyNmFNqMxFGVLqMNjNmVqNnVFRIJFx.VRxjxNG";
    Cifrado b(41,43);
    cadena_2 = b.decodificar(cadena_2);
    cout << "Mensaje descifrado = " << cadena_2 << endl;

    cout << endl;

    string cadena_3 = "p,Lxf,S;LAcX.PcXPLR;.acT,ST.;dL PLX.a;ceP,RXPLSTLX.af dPcL PdLWPQX XSPSTdL TRe;cPdLSTL ;dL,X,;dLSTLAcX.PcXPMLA;cLT  ;NLWT.;dLacTaPcPS;LTdePLdTRRX;,LSTL TRefcPdLaPcPL,X,;dLT,L PLRfP LdTLac;a;,T,LSXdeX,e;dLeTie;dLjLYfTV;dLcT PRX;,PS;dLR;,LRPSPLf,;LSTLT  ;dNLRfjPLUX,P XSPSLTdL PL.Pj;cLSTdT,g; efcPLST L,X,;LeP,e;LP L TTcLR;.;LP LR;.acT,STcL ;L TS;M";
    Cifrado c(15513,31177);
    cadena_3 = c.decodificar(cadena_3);
    cout << "Mensaje descifrado = " << cadena_3 << endl;

    cout << endl;

    string cadena_4 = "Hola Risco soy Fabio";
    Cifrado d;
    cadena_4 = d.codificar(cadena_4);
    cout << "Mensaje Cifrado = " << cadena_4 << endl;
    cadena_4 = d.decodificar(cadena_4);
    cout << "Mensaje Descifrado = " << cadena_4 << endl;

    return 0;
}
