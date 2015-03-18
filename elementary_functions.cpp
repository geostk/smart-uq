#include "elementary_functions.h"

template <class T>
Chebyshev_Polynomial<T> composition(const std::vector<T> &coeffs, const Chebyshev_Polynomial<T> &other){
    int nvar =  other.get_nvar();
    int degree = other.get_degree();

    std::vector<Chebyshev_Polynomial<T> > v;
    Chebyshev_Polynomial<T> res(nvar, degree);

    for(int i=0; i<=degree; i++){
        v.push_back(Chebyshev_Polynomial<T>(nvar,degree));
    }

    v[0] = 1.0;
    v[1] = other;

    for (int i=2; i<=degree; i++){
        v[i] = 2.0 * other * v[i-1] - v[i-2];
    }

    for (int i=0; i<=degree; i++){
        res += v[i]*coeffs[i];
    }

    return res;
}

/************************************************/
/*                  SIN                         */
/************************************************/
template <class T>
Chebyshev_Polynomial<T> sin(const Chebyshev_Polynomial<T> &other){
    int nvar =  other.get_nvar();
    int degree = other.get_degree();
    Chebyshev_Polynomial<T> res(nvar,degree);

    //chebyshev expansion of exp in [-1,1]
    std::vector<T> cheb_sin(Chebyshev_Polynomial<T>::MAX_DEGREE+1);
    cheb_sin[0] = 0.0;
    cheb_sin[1] = 0.880101171489867;
    cheb_sin[2] = 0.0;
    cheb_sin[3] = -0.039126707965337;
    cheb_sin[4] = 0.0;
    cheb_sin[5] = 0.000499515460422;
    cheb_sin[6] = 0.0;
    cheb_sin[7] = -0.000003004651635;
    cheb_sin[8] = 0.0;
    cheb_sin[9] = 0.000000010498500;
    cheb_sin[10] = 0.0;
    cheb_sin[11] = -0.000000000023960;
    cheb_sin[12] = 0.0;
    cheb_sin[13] = 0.000000000000039;

    res = composition(cheb_sin, other);

    return res;
}
template class Chebyshev_Polynomial<double>
sin(const Chebyshev_Polynomial<double> &);
template class Chebyshev_Polynomial<float>
sin(const Chebyshev_Polynomial<float> &);
template class Chebyshev_Polynomial<long double>
sin(const Chebyshev_Polynomial<long double> &);


/************************************************/
/*                  COS                         */
/************************************************/
template <class T>
Chebyshev_Polynomial<T> cos(const Chebyshev_Polynomial<T> &other){
    int nvar =  other.get_nvar();
    int degree = other.get_degree();
    Chebyshev_Polynomial<T> res(nvar,degree);

    //chebyshev expansion of exp in [-1,1]
    std::vector<T> cheb_cos(Chebyshev_Polynomial<T>::MAX_DEGREE+1);
    cheb_cos[0] = 0.765197686557967;
    cheb_cos[1] = 0.0;
    cheb_cos[2] = -0.229806969863801;
    cheb_cos[3] = 0.0;
    cheb_cos[4] = 0.004953277928220;
    cheb_cos[5] = 0.0;
    cheb_cos[6] = -0.000041876676005;
    cheb_cos[7] = 0.0;
    cheb_cos[8] = 0.000000188446883;
    cheb_cos[9] = 0.0;
    cheb_cos[10] = -0.000000000526123;
    cheb_cos[11] = 0.0;
    cheb_cos[12] = 0.000000000001000;
    cheb_cos[13] = 0.0;
    cheb_cos[14] = -0.000000000000001;

    res = composition(cheb_cos, other);

    return res;
}
template class Chebyshev_Polynomial<double>
cos(const Chebyshev_Polynomial<double> &);
template class Chebyshev_Polynomial<float>
cos(const Chebyshev_Polynomial<float> &);
template class Chebyshev_Polynomial<long double>
cos(const Chebyshev_Polynomial<long double> &);

/************************************************/
/*                  TAN                         */
/************************************************/
template <class T>
Chebyshev_Polynomial<T> tan(const Chebyshev_Polynomial<T> &other){
    int nvar =  other.get_nvar();
    int degree = other.get_degree();
    Chebyshev_Polynomial<T> res(nvar,degree);

    //chebyshev expansion of exp in [-1,1]
    std::vector<T> cheb_tan(Chebyshev_Polynomial<T>::MAX_DEGREE+1);
    cheb_tan[0] = 0.0;
    cheb_tan[1] = 1.380043156551057;
    cheb_tan[2] = 0.0;
    cheb_tan[3] = 0.154602898469059;
    cheb_tan[4] = 0.0;
    cheb_tan[5] = 0.019822595597444;
    cheb_tan[6] = 0.0;
    cheb_tan[7] = 0.002559386201352;
    cheb_tan[8] = 0.0;
    cheb_tan[9] = 0.000330635369666;
    cheb_tan[10] = 0.0;
    cheb_tan[11] = 0.000042715278219;
    cheb_tan[12] = 0.0;
    cheb_tan[13] = 0.000005518473592;
    cheb_tan[14] = 0.0;
    cheb_tan[15] = 0.000000712943079;
    cheb_tan[16] = 0.0;
    cheb_tan[17] = 0.000000092106602;
    cheb_tan[18] = 0.0;
    cheb_tan[19] = 0.000000011899444;
    cheb_tan[20] = 0.0;
//to be added if MAX_DEGREE increase
//    cheb_tan[21] = 0.000000001537314;
//    cheb_tan[22] = 0.0;
//    cheb_tan[23] = 0.000000000198609;
//    cheb_tan[24] = 0.0;
//    cheb_tan[25] = 0.000000000025659;
//    cheb_tan[26] = 0.0;
//    cheb_tan[27] = 0.000000000003315;
//    cheb_tan[28] = 0.0;
//    cheb_tan[29] = 0.000000000000428;
//    cheb_tan[30] = 0.0;
//    cheb_tan[31] = 0.000000000000055;
//    cheb_tan[32] = 0.0;
//    cheb_tan[33] = 0.000000000000007;
//    cheb_tan[34] = 0.0;
//    cheb_tan[35] = 0.000000000000001;

    res = composition(cheb_tan, other);

    return res;
}
template class Chebyshev_Polynomial<double>
tan(const Chebyshev_Polynomial<double> &);
template class Chebyshev_Polynomial<float>
tan(const Chebyshev_Polynomial<float> &);
template class Chebyshev_Polynomial<long double>
tan(const Chebyshev_Polynomial<long double> &);

/************************************************/
/*                  COT                         */
/************************************************/
template <class T>
Chebyshev_Polynomial<T> cot(const Chebyshev_Polynomial<T> &other){
    std::cout<<"NOT IMPLEMENTED"<<std::endl;

}
template class Chebyshev_Polynomial<double>
cot(const Chebyshev_Polynomial<double> &);
template class Chebyshev_Polynomial<float>
cot(const Chebyshev_Polynomial<float> &);
template class Chebyshev_Polynomial<long double>
cot(const Chebyshev_Polynomial<long double> &);

/************************************************/
/*                  ASIN                        */
/************************************************/
template <class T>
Chebyshev_Polynomial<T> asin(const Chebyshev_Polynomial<T> &other){
    std::cout<<"NOT IMPLEMENTED"<<std::endl;

}
template class Chebyshev_Polynomial<double>
asin(const Chebyshev_Polynomial<double> &);
template class Chebyshev_Polynomial<float>
asin(const Chebyshev_Polynomial<float> &);
template class Chebyshev_Polynomial<long double>
asin(const Chebyshev_Polynomial<long double> &);

/************************************************/
/*                  ACOS                        */
/************************************************/
template <class T>
Chebyshev_Polynomial<T> acos(const Chebyshev_Polynomial<T> &other){
    std::cout<<"NOT IMPLEMENTED"<<std::endl;

}
template class Chebyshev_Polynomial<double>
acos(const Chebyshev_Polynomial<double> &);
template class Chebyshev_Polynomial<float>
acos(const Chebyshev_Polynomial<float> &);
template class Chebyshev_Polynomial<long double>
acos(const Chebyshev_Polynomial<long double> &);

/************************************************/
/*                  ATAN                        */
/************************************************/
template <class T>
Chebyshev_Polynomial<T> atan(const Chebyshev_Polynomial<T> &other){
    int nvar =  other.get_nvar();
    int degree = other.get_degree();
    Chebyshev_Polynomial<T> res(nvar,degree);

    //chebyshev expansion of exp in [-1,1]
    std::vector<T> cheb_atan(Chebyshev_Polynomial<T>::MAX_DEGREE+1);
    cheb_atan[0] = 0.0;
    cheb_atan[1] = 0.828427124746190;
    cheb_atan[2] = 0.0;
    cheb_atan[3] = -0.047378541243650;
    cheb_atan[4] = 0.0;
    cheb_atan[5] = 0.004877323527903;
    cheb_atan[6] = 0.0;
    cheb_atan[7] = -0.000597726015161;
    cheb_atan[8] = 0.0;
    cheb_atan[9] = 0.000079763888583;
    cheb_atan[10] = 0.0;
    cheb_atan[11] = -0.000011197079759;
    cheb_atan[12] = 0.0;
    cheb_atan[13] = 0.000001625558989;
    cheb_atan[14] = 0.0;
    cheb_atan[15] = -0.000000241714919;
    cheb_atan[16] = 0.0;
    cheb_atan[17] = 0.000000036592697;
    cheb_atan[18] = 0.0;
    cheb_atan[19] = -0.000000005617439;
    cheb_atan[20] = 0.0;
//to be added if MAX_DEGREE increase
//    cheb_atan[21] = 0.000000000872010;
//    cheb_atan[22] = 0.0;
//    cheb_atan[23] = -0.000000000136603;
//    cheb_atan[24] = 0.0;
//    cheb_atan[25] = 0.000000000021562;
//    cheb_atan[26] = 0.0;
//    cheb_atan[27] = -0.000000000003425;
//    cheb_atan[28] = 0.0;
//    cheb_atan[29] = 0.000000000000547;
//    cheb_atan[30] = 0.0;
//    cheb_atan[31] = -0.000000000000088;
//    cheb_atan[32] = 0.0;
//    cheb_atan[33] = 0.000000000000014;
//    cheb_atan[34] = 0.0;
//    cheb_atan[35] = -0.000000000000002;

    res = composition(cheb_atan, other);

    return res;
}
template class Chebyshev_Polynomial<double>
atan(const Chebyshev_Polynomial<double> &);
template class Chebyshev_Polynomial<float>
atan(const Chebyshev_Polynomial<float> &);
template class Chebyshev_Polynomial<long double>
atan(const Chebyshev_Polynomial<long double> &);

/************************************************/
/*                  ACOT                        */
/************************************************/
template <class T>
Chebyshev_Polynomial<T> acot(const Chebyshev_Polynomial<T> &other){
    std::cout<<"NOT IMPLEMENTED"<<std::endl;

}
template class Chebyshev_Polynomial<double>
acot(const Chebyshev_Polynomial<double> &);
template class Chebyshev_Polynomial<float>
acot(const Chebyshev_Polynomial<float> &);
template class Chebyshev_Polynomial<long double>
acot(const Chebyshev_Polynomial<long double> &);



// OTHERS
//EXPONENTIAL FUNCTION
template <class T>
/************************************************/
/*                  EXP                         */
/************************************************/
Chebyshev_Polynomial<T> exp(const Chebyshev_Polynomial<T> &other){
    int nvar =  other.get_nvar();
    int degree = other.get_degree();
    Chebyshev_Polynomial<T> res(nvar,degree);

    //chebyshev expansion of exp in [-1,1]
    std::vector<T> cheb_exp(Chebyshev_Polynomial<T>::MAX_DEGREE+1);
    cheb_exp[0] = 1.266065877752008;
    cheb_exp[1] = 1.130318207984970;
    cheb_exp[2] = 0.271495339534077;
    cheb_exp[3] = 0.044336849848664;
    cheb_exp[4] = 0.005474240442094;
    cheb_exp[5] = 0.000542926311914;
    cheb_exp[6] = 0.000044977322954;
    cheb_exp[7] = 0.000003198436462;
    cheb_exp[8] = 0.000000199212481;
    cheb_exp[9] = 0.000000011036772;
    cheb_exp[10] = 0.000000000550590;
    cheb_exp[11] = 0.000000000024980;
    cheb_exp[12] = 0.000000000001039;
    cheb_exp[13] = 0.000000000000040;
    cheb_exp[14] = 0.000000000000001;

    res = composition(cheb_exp, other);

    return res;
}
template class Chebyshev_Polynomial<double>
exp(const Chebyshev_Polynomial<double> &);
template class Chebyshev_Polynomial<float>
exp(const Chebyshev_Polynomial<float> &);
template class Chebyshev_Polynomial<long double>
exp(const Chebyshev_Polynomial<long double> &);


/************************************************/
/*                  SQRT                        */
/************************************************/
template <class T>
Chebyshev_Polynomial<T> sqrt(const Chebyshev_Polynomial<T> &other){
    std::cout<<"NOT IMPLEMENTED"<<std::endl;

}
template class Chebyshev_Polynomial<double>
sqrt(const Chebyshev_Polynomial<double> &);
template class Chebyshev_Polynomial<float>
sqrt(const Chebyshev_Polynomial<float> &);
template class Chebyshev_Polynomial<long double>
sqrt(const Chebyshev_Polynomial<long double> &);

/************************************************/
/*                  LOG                         */
/************************************************/
template <class T>
Chebyshev_Polynomial<T> log(const Chebyshev_Polynomial<T> &other){
    std::cout<<"NOT IMPLEMENTED"<<std::endl;

}
template class Chebyshev_Polynomial<double>
log(const Chebyshev_Polynomial<double> &);
template class Chebyshev_Polynomial<float>
log(const Chebyshev_Polynomial<float> &);
template class Chebyshev_Polynomial<long double>
log(const Chebyshev_Polynomial<long double> &);

/************************************************/
/*                  LOG10                       */
/************************************************/
template <class T>
Chebyshev_Polynomial<T> log10(const Chebyshev_Polynomial<T> &other){

}
template class Chebyshev_Polynomial<double>
log10(const Chebyshev_Polynomial<double> &);
template class Chebyshev_Polynomial<float>
log10(const Chebyshev_Polynomial<float> &);
template class Chebyshev_Polynomial<long double>
log10(const Chebyshev_Polynomial<long double> &);

/************************************************/
/*                  POW                         */
/************************************************/
template <class T>
Chebyshev_Polynomial<T> pow(const Chebyshev_Polynomial<T> &other, const int &exponent){
    if(exponent<=1){
        std::cout<<"pow function with integer exponent, integer must be > 1"<<std::endl;
        exit(EXIT_FAILURE);
    }
    int nvar =  other.get_nvar();
    int degree = other.get_degree();
    Chebyshev_Polynomial<T> res(nvar,degree);

    res = other;
    for(int i=1; i<exponent; i++)
        res *= other;

    return res;
}
template class Chebyshev_Polynomial<double>
pow(const Chebyshev_Polynomial<double> &, const int &);
template class Chebyshev_Polynomial<float>
pow(const Chebyshev_Polynomial<float> &, const int &);
template class Chebyshev_Polynomial<long double>
pow(const Chebyshev_Polynomial<long double> &, const int &);



template <class T>
Chebyshev_Polynomial<T> pow(const Chebyshev_Polynomial<T> &other, const double &exponent){
std::cout<<"NOT IMPLEMENTED"<<std::endl;

}
template class Chebyshev_Polynomial<double>
pow(const Chebyshev_Polynomial<double> &, const double &);
template class Chebyshev_Polynomial<float>
pow(const Chebyshev_Polynomial<float> &, const double &);
template class Chebyshev_Polynomial<long double>
pow(const Chebyshev_Polynomial<long double> &, const double &);


/************************************************/
/*                  INV                         */
/************************************************/
template <class T>
Chebyshev_Polynomial<T> inv(const Chebyshev_Polynomial<T> &other){
    int nvar =  other.get_nvar();
    int degree = other.get_degree();
    Chebyshev_Polynomial<T> res(nvar,degree);

    //chebyshev expansion of 1/x in [1,3]
    std::vector<T> cheb_inv(Chebyshev_Polynomial<T>::MAX_DEGREE+1);
    cheb_inv[0] = 0.577350269189626;
    cheb_inv[1] = -0.309401076758503;
    cheb_inv[2] = 0.082903768654761;
    cheb_inv[3] = -0.022213997860540;
    cheb_inv[4] = 0.005952222787398;
    cheb_inv[5] = -0.001594893289054;
    cheb_inv[6] = 0.000427350368816;
    cheb_inv[7] = -0.000114508186209;
    cheb_inv[8] = 0.000030682376022;
    cheb_inv[9] = -0.000008221317877;
    cheb_inv[10] = 0.000002202895486;
    cheb_inv[11] = -0.000000590264066;
    cheb_inv[12] = 0.000000158160780;
    cheb_inv[13] = -0.000000042379053;
    cheb_inv[14] = 0.000000011355433;
    cheb_inv[15] = -0.000000003042679;
    cheb_inv[16] = 0.000000000815283;
    cheb_inv[17] = -0.000000000218455;
    cheb_inv[18] = 0.000000000058535;
    cheb_inv[19] = -0.000000000015684;
    cheb_inv[20] = 0.000000000004203;
//    cheb_inv[21] = -0.000000000001126;
//    cheb_inv[22] = 0.000000000000302;
//    cheb_inv[23] = -0.000000000000081;
//    cheb_inv[24] = 0.000000000000022;
//    cheb_inv[25] = -0.000000000000006;
//    cheb_inv[26] = 0.000000000000002;

    res = composition(cheb_inv, other);

    return res;
}
template class Chebyshev_Polynomial<double>
inv(const Chebyshev_Polynomial<double> &);
template class Chebyshev_Polynomial<float>
inv(const Chebyshev_Polynomial<float> &);
template class Chebyshev_Polynomial<long double>
inv(const Chebyshev_Polynomial<long double> &);
