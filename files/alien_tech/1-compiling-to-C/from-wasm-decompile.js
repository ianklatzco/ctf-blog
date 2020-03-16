import memory env_memory;

global g_a:int = 5246544;
export global data_end:int = 3664;
global g_c:int = 0;

import table env_table:funcref;

data d_ABCDEFGHIJKLMNOPQRSTUVWXYZab(offset: 1024) = 
  "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/\00%d\0a"
  "\00-+   0X0x\00(null)\00\00\00\00\00\00\00\00\00\00\00\11\00\0a\00\11\11"
  "\11\00\00\00\00\05\00\00\00\00\00\00\09\00\00\00\00\0b\00\00\00\00\00\00"
  "\00\00\11\00\0f\0a\11\11\11\03\0a\07\00\01\13\09\0b\0b\00\00\09\06\0b\00"
  "\00\0b\00\06\11\00\00\00\11\11\11\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\0b\00\00\00\00\00\00\00\00\11\00\0a\0a\11\11\11\00\0a\00\00\02"
  "\00\09\0b\00\00\00\09\00\0b\00\00\0b\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\0c\00\00\00\00\00\00\00\00\00\00"
  "\00\0c\00\00\00\00\0c\00\00\00\00\09\0c\00\00\00\00\00\0c\00\00\0c\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\0e"
  "\00\00\00\00\00\00\00\00\00\00\00\0d\00\00\00\04\0d\00\00\00\00\09\0e\00"
  "\00\00\00\00\0e\00\00\0e\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\10\00\00\00\00\00\00\00\00\00\00\00\0f\00\00"
  "\00\00\0f\00\00\00\00\09\10\00\00\00\00\00\10\00\00\10\00\00\12\00\00\00"
  "\12\12\12\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\12\00\00\00\12\12\12\00\00\00\00\00\00\09\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\0b\00\00\00\00\00\00\00\00\00\00\00\0a\00\00\00\00\0a\00"
  "\00\00\00\09\0b\00\00\00\00\00\0b\00\00\0b\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\0c\00\00\00\00\00\00\00\00"
  "\00\00\00\0c\00\00\00\00\0c\00\00\00\00\09\0c\00\00\00\00\00\0c\00\00\0c"
  "\00\000123456789ABCDEF-0X+0X 0X-0x+0x 0x\00inf\00INF\00nan\00NAN\00.\00"
  "\00\00\00h\07\00\00";
data d_iB7Hh(offset: 1648) = 
  "\90iB7\13\08\10\09\08\07\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00,\08\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\05\00\00\00\00\00\00\00\00\00\00\00\03\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\04\00\00\00\05\00"
  "\00\00H\0a\00\00\00\04\00\00\00\00\00\00\00\00\00\00\01\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\0a\ff\ff\ff\ff\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00h\07\00\00";
data d_c(offset: 2048) = 
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00"
  "\00\00\00\00\00\00\00\00";

import function wasi_snapshot_preview1_fd_write(a:int, b:int, c:int, d:int):int;

import function env_emscripten_resize_heap(a:int):int;

import function env_emscripten_memcpy_big(a:int, b:int, c:int):int;

import function env_handle_stack_overflow();

import function env_setTempRet0(a:int);

function f_f():int {
  return 3664
}

export function wasm_call_ctors() {
}

function f_h(a:int, b:int, c:int):int {
  var d:int = g_a;
  var e:int = 304;
  var f:int = d - e;
  var lh:int = f;
  if (lh < g_c) { env_handle_stack_overflow() }
  g_a = lh;
  label B_a:
  var g:int = 0;
  var h:int = 32;
  var i:int = f + h;
  var j:int = i;
  f[74]:int = a;
  f[73]:int = b;
  f[72]:int = c;
  f[0]:int = g;
  var k:int = 256;
  var l:int = 128;
  f_qa(j, l, k);
  f[3]:int = g;
  loop L_d {
    var m:int = 64;
    var n:int = f[3]:int;
    var o:int = n;
    var p:int = m;
    var q:int = o < p;
    var r:int = 1;
    var s:int = q & r;
    if (eqz(s)) goto B_c;
    var t:int = 32;
    var u:int = f + t;
    var v:int = u;
    var w:int = f[3]:int;
    var x:ubyte_ptr = f[3]:int;
    var y:int = x[1024];
    var z:int = 255;
    var aa:int = y & z;
    var ba:byte_ptr = v + aa;
    ba[0] = w;
    var ca:int = f[3]:int;
    var da:int = 1;
    var ea:int = ca + da;
    f[3]:int = ea;
    continue L_d;
    unreachable;
  }
  unreachable;
  label B_c:
  var fa:int = 0;
  var ga:int = 0;
  f[93]:byte = ga;
  f[2]:int = fa;
  f[3]:int = fa;
  loop L_f {
    var ha:int = f[3]:int;
    var ia:int = f[73]:int;
    var ja:int = ha;
    var ka:int = ia;
    var la:int = ja < ka;
    var ma:int = 1;
    var na:int = la & ma;
    if (eqz(na)) goto B_e;
    var oa:int = 128;
    var pa:int = 32;
    var qa:int = f + pa;
    var ra:int = qa;
    var sa:int = f[74]:int;
    var ta:int = f[3]:int;
    var ua:ubyte_ptr = sa + ta;
    var va:int = ua[0];
    var wa:int = 255;
    var xa:int = va & wa;
    var ya:ubyte_ptr = ra + xa;
    var za:int = ya[0];
    var ab:int = 255;
    var bb:int = za & ab;
    var cb:int = bb;
    var db:int = oa;
    var eb:int = cb != db;
    var fb:int = 1;
    var gb:int = eb & fb;
    if (eqz(gb)) goto B_g;
    var hb:int = f[2]:int;
    var ib:int = 1;
    var jb:int = hb + ib;
    f[2]:int = jb;
    label B_g:
    var kb:int = f[3]:int;
    var lb:int = 1;
    var mb:int = kb + lb;
    f[3]:int = mb;
    continue L_f;
    unreachable;
  }
  unreachable;
  label B_e:
  var nb:int = f[2]:int;
  if (eqz(nb)) goto B_j;
  var ob:int = f[2]:int;
  var pb:int = 3;
  var qb:int = ob & pb;
  if (eqz(qb)) goto B_i;
  label B_j:
  var rb:int = 0;
  f[75]:int = rb;
  goto B_h;
  label B_i:
  var sb:int = 0;
  var tb:int = f[2]:int;
  var ub:int = 2;
  var vb:int = tb >> ub;
  var wb:int = 3;
  var xb:int = vb * wb;
  f[1]:int = xb;
  var yb:int = f[1]:int;
  var zb:int = malloc(yb);
  f[7]:int = zb;
  f[6]:int = zb;
  var ac:int = f[7]:int;
  var bc:int = ac;
  var cc:int = sb;
  var dc:int = bc == cc;
  var ec:int = 1;
  var fc:int = dc & ec;
  if (eqz(fc)) goto B_k;
  var gc:int = 0;
  f[75]:int = gc;
  goto B_h;
  label B_k:
  var hc:int = 0;
  f[2]:int = hc;
  f[3]:int = hc;
  loop L_m {
    var ic:int = f[3]:int;
    var jc:int = f[73]:int;
    var kc:int = ic;
    var lc:int = jc;
    var mc:int = kc < lc;
    var nc:int = 1;
    var oc:int = mc & nc;
    if (eqz(oc)) goto B_l;
    var pc:int = 128;
    var qc:int = 32;
    var rc:int = f + qc;
    var sc:int = rc;
    var tc:int = f[74]:int;
    var uc:int = f[3]:int;
    var vc:ubyte_ptr = tc + uc;
    var wc:int = vc[0];
    var xc:int = 255;
    var yc:int = wc & xc;
    var zc:ubyte_ptr = sc + yc;
    var ad:int = zc[0];
    f[19]:byte = ad;
    var bd:int = f[19]:ubyte;
    var cd:int = 255;
    var dd:int = bd & cd;
    var ed:int = dd;
    var fd:int = pc;
    var gd:int = ed == fd;
    var hd:int = 1;
    var id:int = gd & hd;
    if (eqz(id)) goto B_o;
    goto B_n;
    label B_o:
    var jd:int = 61;
    var kd:int = f[74]:int;
    var ld:int = f[3]:int;
    var md:ubyte_ptr = kd + ld;
    var nd:int = md[0];
    var od:int = 255;
    var pd:int = nd & od;
    var qd:int = pd;
    var rd:int = jd;
    var sd:int = qd == rd;
    var td:int = 1;
    var ud:int = sd & td;
    if (eqz(ud)) goto B_p;
    var vd:int = f[0]:int;
    var wd:int = 1;
    var xd:int = vd + wd;
    f[0]:int = xd;
    label B_p:
    var yd:int = 4;
    var zd:int = 20;
    var ae:int = f + zd;
    var be:int = ae;
    var ce:int = f[19]:ubyte;
    var de:int = f[2]:int;
    var ee:byte_ptr = be + de;
    ee[0] = ce;
    var fe:int = f[2]:int;
    var ge:int = 1;
    var he:int = fe + ge;
    f[2]:int = he;
    var ie:int = f[2]:int;
    var je:int = ie;
    var ke:int = yd;
    var le:int = je == ke;
    var me:int = 1;
    var ne:int = le & me;
    if (eqz(ne)) goto B_q;
    var oe:int = 0;
    var pe:int = f[20]:ubyte;
    var qe:int = 255;
    var re:int = pe & qe;
    var se:int = 2;
    var te:int = re << se;
    var ue:int = f[21]:ubyte;
    var ve:int = 255;
    var we:int = ue & ve;
    var xe:int = 4;
    var ye:int = we >> xe;
    var ze:int = te | ye;
    var af:byte_ptr = f[6]:int;
    var bf:int = 1;
    var cf:int = af + bf;
    f[6]:int = cf;
    af[0] = ze;
    var df:int = f[21]:ubyte;
    var ef:int = 255;
    var ff:int = df & ef;
    var gf:int = 4;
    var hf:int = ff << gf;
    var if:int = f[22]:ubyte;
    var jf:int = 255;
    var kf:int = if & jf;
    var lf:int = 2;
    var mf:int = kf >> lf;
    var nf:int = hf | mf;
    var of:byte_ptr = f[6]:int;
    var pf:int = 1;
    var qf:int = of + pf;
    f[6]:int = qf;
    of[0] = nf;
    var rf:int = f[22]:ubyte;
    var sf:int = 255;
    var tf:int = rf & sf;
    var uf:int = 6;
    var vf:int = tf << uf;
    var wf:int = f[23]:ubyte;
    var xf:int = 255;
    var yf:int = wf & xf;
    var zf:int = vf | yf;
    var ag:byte_ptr = f[6]:int;
    var bg:int = 1;
    var cg:int = ag + bg;
    f[6]:int = cg;
    ag[0] = zf;
    f[2]:int = oe;
    var dg:int = f[0]:int;
    if (eqz(dg)) goto B_r;
    var eg:int = 1;
    var fg:int = f[0]:int;
    var gg:int = fg;
    var hg:int = eg;
    var ig:int = gg == hg;
    var jg:int = 1;
    var kg:int = ig & jg;
    if (eqz(kg)) goto B_t;
    var lg:int = f[6]:int;
    var mg:int = -1;
    var ng:int = lg + mg;
    f[6]:int = ng;
    goto B_s;
    label B_t:
    var og:int = 2;
    var pg:int = f[0]:int;
    var qg:int = pg;
    var rg:int = og;
    var sg:int = qg == rg;
    var tg:int = 1;
    var ug:int = sg & tg;
    if (eqz(ug)) goto B_v;
    var vg:int = f[6]:int;
    var wg:int = -2;
    var xg:int = vg + wg;
    f[6]:int = xg;
    goto B_u;
    label B_v:
    var yg:int = 0;
    var zg:int = f[7]:int;
    free(zg);
    f[75]:int = yg;
    goto B_h;
    label B_u:
    label B_s:
    goto B_l;
    label B_r:
    label B_q:
    label B_n:
    var ah:int = f[3]:int;
    var bh:int = 1;
    var ch:int = ah + bh;
    f[3]:int = ch;
    continue L_m;
    unreachable;
  }
  unreachable;
  label B_l:
  var dh:int = f[6]:int;
  var eh:int = f[7]:int;
  var fh:int = dh - eh;
  var gh:int_ptr = f[72]:int;
  gh[0] = fh;
  var hh:int = f[7]:int;
  f[75]:int = hh;
  label B_h:
  var ih:int = f[75]:int;
  var jh:int = 304;
  var kh:int = f + jh;
  var mh:int = kh;
  if (mh < g_c) { env_handle_stack_overflow() }
  g_a = mh;
  label B_w:
  return ih;
}

function f_i() {
  var a:ubyte_ptr = 0;
  var b:int = a[1648];
  var c:int = 24;
  var d:int = b << c;
  var e:int = d >> c;
  var f:int = 222;
  var g:int = e ^ f;
  var h:byte_ptr = 0;
  h[1648] = g;
  var i:ubyte_ptr = 0;
  var j:int = i[1649];
  var k:int = 24;
  var l:int = j << k;
  var m:int = l >> k;
  var n:int = 73;
  var o:int = m ^ n;
  var p:byte_ptr = 0;
  p[1649] = o;
  var q:ubyte_ptr = 0;
  var r:int = q[1650];
  var s:int = 24;
  var t:int = r << s;
  var u:int = t >> s;
  var v:int = 5;
  var w:int = u ^ v;
  var x:byte_ptr = 0;
  x[1650] = w;
  var y:ubyte_ptr = 0;
  var z:int = y[1651];
  var aa:int = 24;
  var ba:int = z << aa;
  var ca:int = ba >> aa;
  var da:int = 88;
  var ea:int = ca ^ da;
  var fa:byte_ptr = 0;
  fa[1651] = ea;
  var ga:ubyte_ptr = 0;
  var ha:int = ga[1652];
  var ia:int = 24;
  var ja:int = ha << ia;
  var ka:int = ja >> ia;
  var la:int = 125;
  var ma:int = ka ^ la;
  var na:byte_ptr = 0;
  na[1652] = ma;
  var oa:ubyte_ptr = 0;
  var pa:int = oa[1653];
  var qa:int = 24;
  var ra:int = pa << qa;
  var sa:int = ra >> qa;
  var ta:int = 114;
  var ua:int = sa ^ ta;
  var va:byte_ptr = 0;
  va[1653] = ua;
  var wa:ubyte_ptr = 0;
  var xa:int = wa[1654];
  var ya:int = 24;
  var za:int = xa << ya;
  var ab:int = za >> ya;
  var bb:int = 113;
  var cb:int = ab ^ bb;
  var db:byte_ptr = 0;
  db[1654] = cb;
  var eb:ubyte_ptr = 0;
  var fb:int = eb[1655];
  var gb:int = 24;
  var hb:int = fb << gb;
  var ib:int = hb >> gb;
  var jb:int = 101;
  var kb:int = ib ^ jb;
  var lb:byte_ptr = 0;
  lb[1655] = kb;
  var mb:ubyte_ptr = 0;
  var nb:int = mb[1656];
  var ob:int = 24;
  var pb:int = nb << ob;
  var qb:int = pb >> ob;
  var rb:int = 109;
  var sb:int = qb ^ rb;
  var tb:byte_ptr = 0;
  tb[1656] = sb;
  var ub:ubyte_ptr = 0;
  var vb:int = ub[1657];
  var wb:int = 24;
  var xb:int = vb << wb;
  var yb:int = xb >> wb;
  var zb:int = 125;
  var ac:int = yb ^ zb;
  var bc:byte_ptr = 0;
  bc[1657] = ac;
}

function f_j(a:int, b:int):int {
  var c:int = g_a;
  var d:int = 48;
  var e:int_ptr = c - d;
  var fc:int = e;
  if (fc < g_c) { env_handle_stack_overflow() }
  g_a = fc;
  label B_a:
  var f:int = 1648;
  var g:int = 10;
  var h:int = 32;
  var i:int = e + h;
  var j:int = i;
  var k:int = 255;
  e[10] = a;
  e[9] = b;
  e[8] = k;
  var l:int = e[10];
  var m:int = e[10];
  var n:int = f_cb(m);
  var o:int = f_h(l, n, j);
  e[7] = o;
  var p:int = e[9];
  var q:int = e[9];
  var r:int = f_cb(q);
  var s:int = f_h(p, r, j);
  e[6] = s;
  var t:int = e[6];
  var u:int = f_l(t, f, g);
  e[5] = u;
  var v:int = e[5];
  if (eqz(v)) goto B_d;
  var w:int = -2;
  e[11] = w;
  goto B_c;
  label B_d:
  var x:int = 10;
  var y:int = 1;
  e[4] = y;
  e[3] = x;
  var z:int = e[7];
  var aa:int = f_cb(z);
  e[2] = aa;
  var ba:int = e[6];
  var ca:int = f_cb(ba);
  e[1] = ca;
  loop L_e {
    var da:int = 0;
    var ea:int = e[3];
    var fa:int = e[2];
    var ga:int = ea;
    var ha:int = fa;
    var ia:int = ga < ha;
    var ja:int = 1;
    var ka:int = ia & ja;
    var la:int = da;
    if (eqz(ka)) goto B_f;
    var ma:int = e[3];
    var na:int = e[1];
    var oa:int = ma;
    var pa:int = na;
    var qa:int = oa < pa;
    la = qa;
    label B_f:
    var ra:int = la;
    var sa:int = 1;
    var ta:int = ra & sa;
    if (eqz(ta)) goto B_g;
    var ua:int = e[7];
    var va:int = e[3];
    var wa:ubyte_ptr = ua + va;
    var xa:int = wa[0];
    var ya:int = 24;
    var za:int = xa << ya;
    var ab:int = za >> ya;
    var bb:int = e[6];
    var cb:int = e[3];
    var db:ubyte_ptr = bb + cb;
    var eb:int = db[0];
    var fb:int = 24;
    var gb:int = eb << fb;
    var hb:int = gb >> fb;
    var ib:int = ab;
    var jb:int = hb;
    var kb:int = ib != jb;
    var lb:int = 1;
    var mb:int = kb & lb;
    if (eqz(mb)) goto B_h;
    goto B_g;
    label B_h:
    var nb:int = e[3];
    var ob:int = 1;
    var pb:int = nb + ob;
    e[3] = pb;
    var qb:int = e[4];
    var rb:int = 1;
    var sb:int = qb + rb;
    e[4] = sb;
    continue L_e;
    label B_g:
  }
  var tb:int = e[3];
  var ub:int = e[2];
  var vb:int = tb;
  var wb:int = ub;
  var xb:int = vb == wb;
  var yb:int = 1;
  var zb:int = xb & yb;
  if (eqz(zb)) goto B_i;
  var ac:int = -1;
  e[11] = ac;
  goto B_c;
  label B_i:
  var bc:int = e[4];
  e[11] = bc;
  label B_c:
  var cc:int = e[11];
  var dc:int = 48;
  var ec:int = e + dc;
  var gc:int = ec;
  if (gc < g_c) { env_handle_stack_overflow() }
  g_a = gc;
  label B_j:
  return cc;
}

export function main(a:int, b:int):int {
  var c:int = g_a;
  var d:int = 32;
  var e:int_ptr = c - d;
  var z:int = e;
  if (z < g_c) { env_handle_stack_overflow() }
  g_a = z;
  label B_a:
  var f:int = 3;
  var g:int = 0;
  e[7] = g;
  e[6] = a;
  e[5] = b;
  var h:int = e[6];
  var i:int = h;
  var j:int = f;
  var k:int = i < j;
  var l:int = 1;
  var m:int = k & l;
  if (eqz(m)) goto B_d;
  var n:int = 1;
  e[7] = n;
  goto B_c;
  label B_d:
  f_i();
  var o:int_ptr = e[5];
  var p:int = o[1];
  var q:int_ptr = e[5];
  var r:int = q[2];
  var s:int = f_j(p, r);
  e[4] = s;
  var t:int = e[4];
  e[0] = t;
  var u:int = 1089;
  f_za(u, e);
  var v:int = e[4];
  e[7] = v;
  label B_c:
  var w:int = e[7];
  var x:int = 32;
  var y:int = e + x;
  var aa:int = y;
  if (aa < g_c) { env_handle_stack_overflow() }
  g_a = aa;
  label B_e:
  return w;
}

function f_l(a:{ a:ubyte, b:ubyte }, b:ubyte_ptr, c:int):int {
  var f:int;
  if (c) goto B_a;
  return 0;
  label B_a:
  var d:int = 0;
  var e:int = a.a;
  if (eqz(e)) goto B_b;
  loop L_d {
    if ((e & 255) != (f = b[0])) goto B_c;
    c = c + -1;
    if (eqz(c)) goto B_c;
    if (eqz(f)) goto B_c;
    b = b + 1;
    e = a.b;
    a = a + 1;
    if (e) continue L_d;
    goto B_b;
    unreachable;
  }
  unreachable;
  label B_c:
  d = e;
  label B_b:
  return (d & 255) - b[0];
}

export function errno_location():int {
  return 2048
}

function f_n(a:int):int {
  if (a) goto B_a;
  return 0;
  label B_a:
  errno_location()[0]:int = a;
  return -1;
}

function f_o(a:int, b:{ a:int, b:int }, c:int):int {
  var d:int_ptr;
  var e:int;
  var d:int_ptr;
  var d:int_ptr;
  var d:int_ptr;
  var d:int_ptr;
  var d:int_ptr;
  var d:int_ptr;
  var d:int_ptr;
  var h:int;
  var i:int;
  var d:int_ptr;
  var d:int_ptr;
  var d:int_ptr;
  d = g_a - 32;
  var j:int = d;
  if (j < g_c) { env_handle_stack_overflow() }
  g_a = j;
  label B_a:
  d[4] = (e = a[7]:int);
  var f:int = a[5]:int;
  d[7] = c;
  d[6] = b;
  d[5] = (b = f - e);
  f = b + c;
  var g:int = 2;
  b = d + 16;
  if (
    f_n(wasi_snapshot_preview1_fd_write(a[15]:int, d + 16, 2, d + 12))) goto B_f;
  loop L_g {
    if (f == (e = d[3])) goto B_e;
    if (e <= -1) goto B_d;
    b = select_if(b + 8, b, i = e > (h = b.b));
    b.a = b.a + (h = e - select_if(h, 0, i));
    b.b = b.b - h;
    f = f - e;
    if (
      eqz(
        f_n(wasi_snapshot_preview1_fd_write(a[15]:int, b, g = g - i, d + 12)))) continue L_g;
  }
  label B_f:
  d[3] = -1;
  if (f != -1) goto B_d;
  label B_e:
  a[7]:int = (b = a[11]:int);
  a[5]:int = b;
  a[4]:int = b + a[12]:int;
  e = c;
  goto B_c;
  label B_d:
  e = 0;
  a[7]:int = 0;
  a[2]:long = 0L;
  a[0]:int = a[0]:int | 32;
  if (g == 2) goto B_c;
  e = c - b.b;
  label B_c:
  var k:int = d + 32;
  if (k < g_c) { env_handle_stack_overflow() }
  g_a = k;
  label B_h:
  return e;
}

function f_p(a:int):int {
  return a + -48 < 10
}

function f_q():int {
  return 1660
}

function f_r(a:{ a:byte, b:byte, c:byte, d:byte }, b:int, c:int):int {
  var d:int = 1;
  if (eqz(a)) goto B_b;
  if (b <= 127) goto B_a;
  if ((f_s()[44]:int)[0]:int) goto B_d;
  if ((b & -128) == 57216) goto B_a;
  errno_location()[0]:int = 25;
  goto B_c;
  label B_d:
  if (b > 2047) goto B_e;
  a.b = (b & 63) | 128;
  a.a = b >> 6 | 192;
  return 2;
  label B_e:
  if (b < 55296) goto B_g;
  if ((b & -8192) != 57344) goto B_f;
  label B_g:
  a.c = (b & 63) | 128;
  a.a = b >> 12 | 224;
  a.b = (b >> 6 & 63) | 128;
  return 3;
  label B_f:
  if (b + -65536 > 1048575) goto B_h;
  a.d = (b & 63) | 128;
  a.a = b >> 18 | 240;
  a.c = (b >> 6 & 63) | 128;
  a.b = (b >> 12 & 63) | 128;
  return 4;
  label B_h:
  errno_location()[0]:int = 25;
  label B_c:
  d = -1;
  label B_b:
  return d;
  label B_a:
  a.a = b;
  return 1;
}

function f_s():int {
  return f_q()
}

function f(a:int, b:int):int {
  if (a) goto B_a;
  return 0;
  label B_a:
  return f_r(a, b, 0);
}

function f_u(a:int, b:int, c:int):int {
  var e:int;
  var d:int = c != 0;
  if (eqz(c)) goto B_d;
  if (eqz(a & 3)) goto B_d;
  e = b & 255;
  loop L_e {
    if (a[0]:ubyte == e) goto B_c;
    a = a + 1;
    c = c + -1;
    d = c != 0;
    if (eqz(c)) goto B_d;
    if (a & 3) continue L_e;
  }
  label B_d:
  if (eqz(d)) goto B_b;
  label B_c:
  if (a[0]:ubyte == (b & 255)) goto B_a;
  if (c < 4) goto B_g;
  e = (b & 255) * 16843009;
  loop L_h {
    d = a[0]:int ^ e;
    if (((d ^ -1) & d + -16843009) & -2139062144) goto B_f;
    a = a + 4;
    c = c + -4;
    if (c > 3) continue L_h;
  }
  label B_g:
  if (eqz(c)) goto B_b;
  label B_f:
  d = b & 255;
  loop L_i {
    if (a[0]:ubyte == d) goto B_a;
    a = a + 1;
    c = c + -1;
    if (c) continue L_i;
  }
  label B_b:
  return 0;
  label B_a:
  return a;
}

function f_v(a:double, b:int_ptr):double {
  var d:long = i64_reinterpret_f64(a);
  var c:int = i32_wrap_i64(d >> 52L) & 2047;
  if (c == 2047) goto B_a;
  if (c) goto B_b;
  if (a != 0.0) goto B_d;
  c = 0;
  goto B_c;
  label B_d:
  a = f_v(a * 18446744073709551616.0, b);
  c = b[0] + -64;
  label B_c:
  b[0] = c;
  return a;
  label B_b:
  b[0] = c + -1022;
  a = f64_reinterpret_i64(
        (d & -9218868437227405313L) | 4602678819172646912L);
  label B_a:
  return a;
}

function f_w(a:{ a:long, b:long }, b:long, c:long, d:int) {
  var e:long;
  if (eqz(d & 64)) goto B_b;
  c = b << i64_extend_i32_u(d + -64);
  b = 0L;
  goto B_a;
  label B_b:
  if (eqz(d)) goto B_a;
  c = b >> i64_extend_i32_u(64 - d) | c << (e = i64_extend_i32_u(d));
  b = b << e;
  label B_a:
  a.a = b;
  a.b = c;
}

function f_x(a:{ a:long, b:long }, b:long, c:long, d:int) {
  var e:long;
  if (eqz(d & 64)) goto B_b;
  b = c >> i64_extend_i32_u(d + -64);
  c = 0L;
  goto B_a;
  label B_b:
  if (eqz(d)) goto B_a;
  b = c << i64_extend_i32_u(64 - d) | b >> (e = i64_extend_i32_u(d));
  c = c >> e;
  label B_a:
  a.a = b;
  a.b = c;
}

function f_y(a:long, b:long):double {
  var h:long;
  var h:long;
  var g:long;
  var g:long;
  var g:long;
  var g:long;
  var c:long_ptr;
  var c:long_ptr;
  var g:long;
  var c:long_ptr;
  var g:long;
  var c:long_ptr;
  var g:long;
  var c:long_ptr;
  var c:long_ptr;
  var g:long;
  var h:long;
  var g:long;
  var h:long;
  var h:long;
  var c:long_ptr;
  var h:long;
  c = g_a - 32;
  var e:int = c;
  if (e < g_c) { env_handle_stack_overflow() }
  g_a = e;
  label B_a:
  g = b & 9223372036854775807L;
  if (g + -4323737117252386816L >= g + -4899634919602388992L) goto B_d;
  g = a >> 60L | b << 4L;
  a = a & 1152921504606846975L;
  if (a < 576460752303423489L) goto B_e;
  h = g + 4611686018427387905L;
  goto B_c;
  label B_e:
  h = g + 4611686018427387904L;
  if ((a ^ 576460752303423488L) != 0L) goto B_c;
  h = (h & 1L) + h;
  goto B_c;
  label B_d:
  if (
    select_if(eqz(a), g < 9223090561878065152L, g == 9223090561878065152L)) goto B_f;
  h = ((a >> 60L | b << 4L) & 2251799813685247L) | 9221120237041090560L;
  goto B_c;
  label B_f:
  h = 9218868437227405312L;
  if (g > 4899634919602388991L) goto B_c;
  h = 0L;
  var d:int = i32_wrap_i64(g >> 48L);
  if (d < 15249) goto B_c;
  f_w(c + 16, a, g = (b & 281474976710655L) | 281474976710656L, d + -15233);
  f_x(c, a, g, 15361 - d);
  g = c[0];
  h = g >> 60L | (c + 8)[0]:long << 4L;
  g = (g & 1152921504606846975L) | 
      i64_extend_i32_u((c[2] | (c + 16 + 8)[0]:long) != 0L);
  if (g < 576460752303423489L) goto B_g;
  h = h + 1L;
  goto B_c;
  label B_g:
  if ((g ^ 576460752303423488L) != 0L) goto B_c;
  h = (h & 1L) + h;
  label B_c:
  var f:int = c + 32;
  if (f < g_c) { env_handle_stack_overflow() }
  g_a = f;
  label B_h:
  return f64_reinterpret_i64(h | (b & -9223372036854775808L));
}

function f_z(a:int, b:int, c:int, d:int, e:int):int {
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  f = g_a - 208;
  var i:int = f;
  if (i < g_c) { env_handle_stack_overflow() }
  g_a = i;
  label B_a:
  f[51] = c;
  c = 0;
  f_qa(f + 160, 0, 40);
  f[50] = f[51];
  if (f_aa(0, b, f + 200, f + 80, f + 160, d, e) >= 0) goto B_d;
  b = -1;
  goto B_c;
  label B_d:
  if (a[19]:int < 0) goto B_e;
  c = f_ab(a);
  label B_e:
  var g:int = a[0]:int;
  if (a[74]:byte > 0) goto B_f;
  a[0]:int = g & -33;
  label B_f:
  g = g & 32;
  if (eqz(a[12]:int)) goto B_h;
  b = f_aa(a, b, f + 200, f + 80, f + 160, d, e);
  goto B_g;
  label B_h:
  a[12]:int = 80;
  a[4]:int = f + 80;
  a[7]:int = f;
  a[5]:int = f;
  var h:int = a[11]:int;
  a[11]:int = f;
  b = f_aa(a, b, f + 200, f + 80, f + 160, d, e);
  if (eqz(h)) goto B_g;
  call_indirect(a, 0, 0, a[9]:int);
  a[12]:int = 0;
  a[11]:int = h;
  a[7]:int = 0;
  a[4]:int = 0;
  d = a[5]:int;
  a[5]:int = 0;
  b = select_if(b, -1, d);
  label B_g:
  a[0]:int = (d = a[0]:int) | g;
  b = select_if(-1, b, d & 32);
  if (eqz(c)) goto B_c;
  f_bb(a);
  label B_c:
  var j:int = f + 208;
  if (j < g_c) { env_handle_stack_overflow() }
  g_a = j;
  label B_i:
  return b;
}

function f_aa(a:int, b:int, c:int_ptr, d:int, e:int, f:int, g:int):int {
  var h:int;
  var h:int;
  var h:int;
  var h:int;
  var h:int;
  var o:int;
  var h:int;
  var h:int;
  var o:int;
  var h:int;
  var p:int;
  var p:int;
  var p:int;
  var h:int;
  var p:int;
  var r:int;
  var p:int;
  var o:int;
  var p:int;
  var p:int;
  var r:int;
  var o:int;
  var h:int;
  var o:int;
  var o:int;
  var o:int;
  var o:int;
  var h:int;
  var h:int;
  var s:int;
  var s:int;
  var h:int;
  var s:int;
  var h:int;
  var h:int;
  var h:int;
  var h:int;
  var h:int;
  var h:int;
  var h:int;
  var h:int;
  var o:int;
  var h:int;
  var r:int;
  var o:int;
  var p:int;
  var o:int;
  var o:int;
  var o:int;
  var o:int;
  var h:int;
  var h:int;
  var o:int;
  var h:int;
  var r:int;
  var p:int;
  var r:int;
  var p:int;
  var h:int;
  var p:int;
  var s:int;
  var h:int;
  var h:int;
  var h:int;
  var h:int;
  var h:int;
  var h:int;
  var o:int;
  var p:int;
  var h:int;
  var p:int;
  var p:int;
  var p:int;
  var o:int;
  var p:int;
  var s:int;
  var h:int;
  var o:int;
  var h:int;
  var p:int;
  var p:int;
  var h:int;
  var o:int;
  var p:int;
  var s:int;
  var s:int;
  var s:int;
  var h:int;
  var o:int;
  var r:int;
  var n:int;
  var n:int;
  var n:int;
  var n:int;
  var h:int;
  var s:int;
  var t:int;
  var n:int;
  var h:int;
  var t:int;
  var t:int;
  var v:int;
  var t:int;
  var h:int;
  var h:int;
  var v:int;
  var h:int;
  var h:int;
  var n:int;
  var n:int;
  var h:int;
  var n:int;
  var t:int;
  var t:int;
  var t:int;
  var t:int;
  var n:int;
  var h:int;
  var n:int;
  var h:int;
  var p:int;
  var n:int;
  var n:int;
  var h:int;
  var h:int;
  var h:int;
  var h:int;
  var h:int;
  var h:int;
  var h:int;
  var h:int;
  var y:long;
  var n:int;
  var n:int;
  var t:int;
  var h:int;
  var t:int;
  var y:long;
  var t:int;
  var y:long;
  var t:int;
  var u:int;
  var o:int;
  var t:int;
  var t:int;
  var p:int;
  var s:int;
  var s:int;
  var o:int;
  var o:int;
  var n:int;
  var q:int;
  var u:int;
  var o:int;
  var n:int;
  var r:int;
  var p:int;
  var p:int;
  var o:int;
  var n:int;
  var h:int;
  var u:int;
  h = g_a - 80;
  var w:int = h;
  if (w < g_c) { env_handle_stack_overflow() }
  g_a = w;
  label B_a:
  h[19]:int = b;
  var i:int = h + 55;
  var j:int = h + 56;
  var k:int = 0;
  var l:int = 0;
  b = 0;
  loop L_e {
    if (l < 0) goto B_f;
    if (b <= 2147483647 - l) goto B_g;
    errno_location()[0]:int = 61;
    l = -1;
    goto B_f;
    label B_g:
    l = b + l;
    label B_f:
    var m:ubyte_ptr = h[19]:int;
    b = m;
    n = m[0];
    if (eqz(n)) goto B_u;
    loop L_w {
      n = n & 255;
      if (n) goto B_z;
      n = b;
      goto B_y;
      label B_z:
      if (n != 37) goto B_x;
      n = b;
      loop L_aa {
        if (b[1]:ubyte != 37) goto B_y;
        h[19]:int = (o = b + 2);
        n = n + 1;
        p = b[2]:ubyte;
        b = o;
        if (p == 37) continue L_aa;
      }
      label B_y:
      b = n - m;
      if (eqz(a)) goto B_ba;
      f_ba(a, m, b);
      label B_ba:
      if (b) continue L_e;
      q = -1;
      n = 1;
      o = f_p((h[19]:int)[1]:byte);
      b = h[19]:int;
      if (eqz(o)) goto B_ca;
      if (b[2]:ubyte != 36) goto B_ca;
      q = b[1]:byte + -48;
      k = 1;
      n = 3;
      label B_ca:
      h[19]:int = (b = b + n);
      n = 0;
      r = b[0]:byte;
      p = r + -32;
      if (p <= 31) goto B_ea;
      o = b;
      goto B_da;
      label B_ea:
      o = b;
      p = 1 << p;
      if (eqz(p & 75913)) goto B_da;
      loop L_fa {
        h[19]:int = (o = b + 1);
        n = p | n;
        r = b[1]:byte;
        p = r + -32;
        if (p > 31) goto B_da;
        b = o;
        p = 1 << p;
        if (p & 75913) continue L_fa;
      }
      label B_da:
      if (r != 42) goto B_ha;
      if (eqz(f_p(o[1]:byte))) goto B_ja;
      o = h[19]:int;
      if (o[2]:ubyte != 36) goto B_ja;
      ((o[1]:byte << 2) + e + -192)[0]:int = 10;
      b = o + 3;
      s = ((o[1]:byte << 3) + d + -384)[0]:int;
      k = 1;
      goto B_ia;
      label B_ja:
      if (k) goto B_d;
      k = 0;
      s = 0;
      if (eqz(a)) goto B_ka;
      c[0] = (b = c[0]) + 4;
      s = b[0]:int;
      label B_ka:
      b = h[19]:int + 1;
      label B_ia:
      h[19]:int = b;
      if (s > -1) goto B_ga;
      s = 0 - s;
      n = n | 8192;
      goto B_ga;
      label B_ha:
      s = f_ca(h + 76);
      if (s < 0) goto B_d;
      b = h[19]:int;
      label B_ga:
      t = -1;
      if (b[0]:ubyte != 46) goto B_la;
      if (b[1]:ubyte != 42) goto B_ma;
      if (eqz(f_p(b[2]:byte))) goto B_na;
      b = h[19]:int;
      if (b[3]:ubyte != 36) goto B_na;
      ((b[2]:byte << 2) + e + -192)[0]:int = 10;
      t = ((b[2]:byte << 3) + d + -384)[0]:int;
      h[19]:int = (b = b + 4);
      goto B_la;
      label B_na:
      if (k) goto B_d;
      if (a) goto B_pa;
      t = 0;
      goto B_oa;
      label B_pa:
      c[0] = (b = c[0]) + 4;
      t = b[0]:int;
      label B_oa:
      h[19]:int = (b = h[19]:int + 2);
      goto B_la;
      label B_ma:
      h[19]:int = b + 1;
      t = f_ca(h + 76);
      b = h[19]:int;
      label B_la:
      o = 0;
      loop L_qa {
        p = o;
        u = -1;
        if (b[0]:byte + -65 > 57) goto B_c;
        h[19]:int = (r = b + 1);
        o = b[0]:byte;
        b = r;
        o = (o + p * 58 + 1055)[0]:ubyte;
        if (o + -1 < 8) continue L_qa;
      }
      if (eqz(o)) goto B_c;
      if (o != 19) goto B_ua;
      u = -1;
      if (q <= -1) goto B_ta;
      goto B_c;
      label B_ua:
      if (q < 0) goto B_sa;
      e[q]:int = o;
      h[8]:long = d[q]:long;
      label B_ta:
      b = 0;
      if (eqz(a)) continue L_e;
      goto B_ra;
      label B_sa:
      if (eqz(a)) goto B_h;
      f_da(h + 64, o, c, g);
      r = h[19]:int;
      label B_ra:
      v = n & -65537;
      n = select_if(v, n, n & 8192);
      u = 0;
      q = 1093;
      o = j;
      b = (r + -1)[0]:byte;
      b = select_if(select_if(b & -33, b, (b & 15) == 3), b, p);
      r = b + -88;
      if (r <= 32) goto B_v;
      p = b + -65;
      if (p <= 6) goto B_za;
      if (b != 83) goto B_i;
      if (eqz(t)) goto B_ya;
      o = h[16]:int;
      goto B_wa;
      label B_za:
      br_table[B_t, B_i, B_xa, B_i, B_t, B_t, B_t, ..B_t](p);
      label B_ya:
      b = 0;
      f_ea(a, 32, s, 0, n);
      goto B_va;
      label B_xa:
      h[3]:int = 0;
      h[2]:int = h[8]:long;
      h[16]:int = h + 8;
      t = -1;
      o = h + 8;
      label B_wa:
      b = 0;
      loop L_bb {
        p = o[0]:int;
        if (eqz(p)) goto B_ab;
        p = f(h + 4, p);
        m = p < 0;
        if (m) goto B_cb;
        if (p > t - b) goto B_cb;
        o = o + 4;
        if (t > (b = p + b)) continue L_bb;
        goto B_ab;
        label B_cb:
      }
      u = -1;
      if (m) goto B_c;
      label B_ab:
      f_ea(a, 32, s, b, n);
      if (b) goto B_db;
      b = 0;
      goto B_va;
      label B_db:
      p = 0;
      o = h[16]:int;
      loop L_eb {
        m = o[0]:int;
        if (eqz(m)) goto B_va;
        m = f(h + 4, m);
        p = m + p;
        if (p > b) goto B_va;
        f_ba(a, h + 4, m);
        o = o + 4;
        if (p < b) continue L_eb;
      }
      label B_va:
      f_ea(a, 32, s, b, n ^ 8192);
      b = select_if(s, b, s > b);
      continue L_e;
      label B_x:
      h[19]:int = (o = b + 1);
      n = b[1]:ubyte;
      b = o;
      continue L_w;
      unreachable;
    }
    unreachable;
    label B_v:
    br_table[B_n, B_i, B_i, B_i, B_i, B_i, B_i, B_i, B_i, B_t, B_i, B_r, B_q, B_t, B_t, B_t, B_i, B_q, B_i, B_i, B_i, B_i, B_m, B_p, B_o, B_i, B_i, B_s, B_i, B_l, B_i, B_i, B_n, ..B_n](
      r);
    label B_u:
    u = l;
    if (a) goto B_c;
    if (eqz(k)) goto B_h;
    b = 1;
    loop L_gb {
      n = e[b]:int;
      if (eqz(n)) goto B_fb;
      f_da(d + (b << 3), n, c, g);
      u = 1;
      b = b + 1;
      if (b != 10) continue L_gb;
      goto B_c;
      unreachable;
    }
    unreachable;
    label B_fb:
    u = 1;
    if (b > 9) goto B_c;
    loop L_ib {
      n = b;
      b = n + 1;
      if (b == 10) goto B_hb;
      if (eqz(e[b]:int)) continue L_ib;
    }
    label B_hb:
    u = select_if(-1, 1, n < 9);
    goto B_c;
    label B_t:
    b = call_indirect(a, h[8]:double, s, t, n, b, f);
    continue L_e;
    label B_s:
    u = 0;
    b = h[16]:int;
    m = select_if(b, 1103, b);
    b = f_u(m, 0, t);
    o = select_if(b, m + t, b);
    n = v;
    t = select_if(b - m, t, b);
    goto B_i;
    label B_r:
    h[55]:byte = h[8]:long;
    t = 1;
    m = i;
    o = j;
    n = v;
    goto B_i;
    label B_q:
    y = h[8]:long;
    if (y > -1L) goto B_jb;
    h[8]:long = (y = 0L - y);
    u = 1;
    q = 1093;
    goto B_k;
    label B_jb:
    if (eqz(n & 2048)) goto B_kb;
    u = 1;
    q = 1094;
    goto B_k;
    label B_kb:
    q = select_if(1095, 1093, u = n & 1);
    goto B_k;
    label B_p:
    u = 0;
    q = 1093;
    m = f_fa(h[8]:long, j);
    if (eqz(n & 8)) goto B_j;
    t = select_if(t, (b = j - m) + 1, t > b);
    goto B_j;
    label B_o:
    t = select_if(t, 8, t > 8);
    n = n | 8;
    b = 120;
    label B_n:
    u = 0;
    q = 1093;
    m = f_ga(h[8]:long, j, b & 32);
    if (eqz(n & 8)) goto B_j;
    if (eqz(h[8]:long)) goto B_j;
    q = (b >> 4) + 1093;
    u = 2;
    goto B_j;
    label B_m:
    b = 0;
    n = p & 255;
    if (n > 7) continue L_e;
    br_table[B_rb, B_qb, B_pb, B_ob, B_nb, L_e, B_mb, B_lb, ..B_rb](n)
    label B_rb:
    (h[16]:int)[0]:int = l;
    continue L_e;
    label B_qb:
    (h[16]:int)[0]:int = l;
    continue L_e;
    label B_pb:
    (h[16]:int)[0]:long = i64_extend_i32_s(l);
    continue L_e;
    label B_ob:
    (h[16]:int)[0]:short = l;
    continue L_e;
    label B_nb:
    (h[16]:int)[0]:byte = l;
    continue L_e;
    label B_mb:
    (h[16]:int)[0]:int = l;
    continue L_e;
    label B_lb:
    (h[16]:int)[0]:long = i64_extend_i32_s(l);
    continue L_e;
    label B_l:
    u = 0;
    q = 1093;
    y = h[8]:long;
    label B_k:
    m = f_ha(y, j);
    label B_j:
    n = select_if(n & -65537, n, t > -1);
    y = h[8]:long;
    if (t) goto B_tb;
    if (eqz(eqz(y))) goto B_tb;
    t = 0;
    m = j;
    goto B_sb;
    label B_tb:
    t = select_if(t, b = j - m + eqz(y), t > b);
    label B_sb:
    o = j;
    label B_i:
    f_ea(
      a,
      32,
      b = select_if(o = u + (r = select_if(p = o - m, t, t < p)), s, s < o),
      o,
      n);
    f_ba(a, q, u);
    f_ea(a, 48, b, o, n ^ 65536);
    f_ea(a, 48, r, p, 0);
    f_ba(a, m, p);
    f_ea(a, 32, b, o, n ^ 8192);
    continue L_e;
    label B_h:
  }
  u = 0;
  goto B_c;
  label B_d:
  u = -1;
  label B_c:
  var x:int = h + 80;
  if (x < g_c) { env_handle_stack_overflow() }
  g_a = x;
  label B_ub:
  return u;
}

function f_ba(a:ubyte_ptr, b:int, c:int) {
  if (a[0] & 32) goto B_a;
  f_wa(b, c, a);
  label B_a:
}

function f_ca(a:int_ptr):int {
  var b:int = 0;
  if (eqz(f_p((a[0])[0]:byte))) goto B_a;
  loop L_b {
    var c:{ a:byte, b:byte } = a[0];
    var d:int = c.a;
    a[0] = c + 1;
    b = d + b * 10 + -48;
    if (f_p(c.b)) continue L_b;
  }
  label B_a:
  return b;
}

function f_da(a:int, b:int, c:int_ptr, d:int) {
  if (b > 20) goto B_a;
  b = b + -9;
  if (b > 9) goto B_a;
  br_table[B_k, B_j, B_i, B_h, B_g, B_f, B_e, B_d, B_c, B_b, ..B_k](b)
  label B_k:
  c[0] = (b = c[0]) + 4;
  a[0]:int = b[0]:int;
  return ;
  label B_j:
  c[0] = (b = c[0]) + 4;
  a[0]:long = b[0]:int;
  return ;
  label B_i:
  c[0] = (b = c[0]) + 4;
  a[0]:long = b[0]:uint;
  return ;
  label B_h:
  c[0] = (b = c[0] + 7 & -8) + 8;
  a[0]:long = b[0]:long;
  return ;
  label B_g:
  c[0] = (b = c[0]) + 4;
  a[0]:long = b[0]:short;
  return ;
  label B_f:
  c[0] = (b = c[0]) + 4;
  a[0]:long = b[0]:ushort;
  return ;
  label B_e:
  c[0] = (b = c[0]) + 4;
  a[0]:long = b[0]:byte;
  return ;
  label B_d:
  c[0] = (b = c[0]) + 4;
  a[0]:long = b[0]:ubyte;
  return ;
  label B_c:
  c[0] = (b = c[0] + 7 & -8) + 8;
  a[0]:long = b[0]:long;
  return ;
  label B_b:
  call_indirect(a, c, d);
  label B_a:
}

function f_ea(a:int, b:int, c:int, d:int, e:int) {
  var f:int;
  var f:int;
  var f:int;
  var f:int;
  f = g_a - 256;
  var g:int = f;
  if (g < g_c) { env_handle_stack_overflow() }
  g_a = g;
  label B_a:
  if (c <= d) goto B_c;
  if (e & 73728) goto B_c;
  f_qa(f, b, select_if(c = c - d, 256, d = c < 256));
  if (d) goto B_d;
  loop L_e {
    f_ba(a, f, 256);
    c = c + -256;
    if (c > 255) continue L_e;
  }
  label B_d:
  f_ba(a, f, c);
  label B_c:
  var h:int = f + 256;
  if (h < g_c) { env_handle_stack_overflow() }
  g_a = h;
  label B_f:
}

function f_fa(a:long, b:byte_ptr):int {
  if (eqz(a)) goto B_a;
  loop L_b {
    b = b + -1;
    b[0] = (i32_wrap_i64(a) & 7) | 48;
    a = a >> 3L;
    if (a != 0L) continue L_b;
  }
  label B_a:
  return b;
}

function f_ga(a:long, b:byte_ptr, c:int):int {
  if (eqz(a)) goto B_a;
  loop L_b {
    b = b + -1;
    b[0] = ((i32_wrap_i64(a) & 15) + 1584)[0]:ubyte | c;
    a = a >> 4L;
    if (a != 0L) continue L_b;
  }
  label B_a:
  return b;
}

function f_ha(a:long, b:byte_ptr):int {
  var f:long;
  var f:long;
  var c:int;
  var c:int;
  var c:int;
  var d:int;
  var c:int;
  if (a >= 4294967296L) goto B_b;
  f = a;
  goto B_a;
  label B_b:
  loop L_c {
    b = b + -1;
    b[0] = i32_wrap_i64(a - (f = a / 10L) * 10L) | 48;
    c = a > 42949672959L;
    a = f;
    if (c) continue L_c;
  }
  label B_a:
  c = i32_wrap_i64(f);
  if (eqz(c)) goto B_d;
  loop L_e {
    b = b + -1;
    b[0] = c - (d = c / 10) * 10 | 48;
    var e:int = c > 9;
    c = d;
    if (e) continue L_e;
  }
  label B_d:
  return b;
}

function f_ia(a:int, b:int, c:int):int {
  return f_z(a, b, c, 1, 2)
}

function f_ja(a:int, b:double, c:int, d:int, e:int, f:int):int {
  var g:int;
  var y:long;
  var h:int;
  var j:int_ptr;
  var i:ubyte_ptr;
  var h:int;
  var k:int;
  var g:int;
  var g:int;
  var g:int;
  var g:int;
  var m:int;
  var g:int;
  var g:int;
  var k:int;
  var g:int;
  var g:int;
  var o:int;
  var k:int;
  var k:int;
  var o:int;
  var o:int;
  var o:int;
  var k:int;
  var r:int;
  var o:int;
  var k:int;
  var k:int;
  var y:long;
  var y:long;
  var k:int;
  var k:int;
  var r:int;
  var y:long;
  var k:int;
  var r:int;
  var r:int;
  var k:int;
  var k:int;
  var r:int;
  var k:int;
  var g:int;
  var g:int;
  var o:int;
  var k:int;
  var o:int;
  var o:int;
  var n:ubyte_ptr;
  var m:int;
  var o:int;
  var o:int;
  var r:int;
  var k:int;
  var r:int;
  var r:int;
  var r:int;
  var j:int_ptr;
  var j:int_ptr;
  var r:int;
  var j:int_ptr;
  var o:int;
  var k:int;
  var r:int;
  var r:int;
  var r:int;
  var o:int;
  var k:int;
  var o:int;
  var k:int;
  var g:int;
  var g:int;
  var j:int_ptr;
  var r:int;
  var k:int;
  var k:int;
  var o:int;
  var r:int;
  var k:int;
  var r:int;
  var r:int;
  var o:int;
  var n:ubyte_ptr;
  var m:int;
  var n:ubyte_ptr;
  var m:int;
  var o:int;
  var k:int;
  var o:int;
  var u:byte_ptr;
  var u:byte_ptr;
  var o:int;
  var j:int_ptr;
  var u:byte_ptr;
  var u:byte_ptr;
  var o:int;
  var o:int;
  var j:int_ptr;
  var s:byte_ptr;
  var k:int;
  var o:int;
  var s:byte_ptr;
  var k:int;
  var t:int;
  var v:int;
  var h:int;
  var i:ubyte_ptr;
  var j:int_ptr;
  var u:byte_ptr;
  var j:int_ptr;
  var o:int;
  var j:int_ptr;
  var j:int_ptr;
  var j:int_ptr;
  var r:int;
  var r:int;
  var r:int;
  var j:int_ptr;
  var j:int_ptr;
  var r:int;
  var r:int;
  var o:int;
  var j:int_ptr;
  var o:int;
  var k:int;
  var k:int;
  var o:int;
  var k:int;
  var o:int;
  var r:int;
  var o:int;
  var k:int;
  var m:int;
  var n:ubyte_ptr;
  var n:ubyte_ptr;
  var k:int;
  var v:int;
  var t:int;
  var o:int;
  var j:int_ptr;
  var j:int_ptr;
  var k:int;
  var j:int_ptr;
  var o:int;
  var n:ubyte_ptr;
  var k:int;
  var k:int;
  var n:ubyte_ptr;
  var k:int;
  var n:ubyte_ptr;
  var k:int;
  var k:int;
  var n:ubyte_ptr;
  var k:int;
  var n:ubyte_ptr;
  var v:int;
  var m:int;
  var u:byte_ptr;
  var k:int;
  var k:int;
  var k:int;
  var k:int;
  var k:int;
  var s:byte_ptr;
  var k:int;
  var s:byte_ptr;
  var h:int;
  var n:ubyte_ptr;
  var k:int;
  var i:ubyte_ptr;
  var h:int;
  var j:int_ptr;
  var u:byte_ptr;
  var g:int;
  var g:int;
  var r:int;
  var r:int;
  var r:int;
  var r:int;
  var k:int;
  var g:int;
  var k:int;
  var k:int;
  var k:int;
  var g:int;
  var k:int;
  var g:int;
  var u:byte_ptr;
  var k:int;
  var k:int;
  var r:int;
  var r:int;
  var m:int;
  var r:int;
  var o:int;
  var n:ubyte_ptr;
  var r:int;
  var k:int;
  var g:int;
  var k:int;
  var k:int;
  var k:int;
  var g:int;
  var k:int;
  var n:ubyte_ptr;
  var n:ubyte_ptr;
  var n:ubyte_ptr;
  var r:int;
  var r:int;
  var o:int;
  var n:ubyte_ptr;
  var k:int;
  var n:ubyte_ptr;
  var o:int;
  var r:int;
  var t:int;
  var g:int;
  var g:int;
  var r:int;
  var o:int;
  var k:int;
  var o:int;
  var g:int;
  var r:int;
  var k:int;
  var g:int;
  var k:int;
  var k:int;
  var k:int;
  var g:int;
  var k:int;
  var k:int;
  var v:int;
  var n:ubyte_ptr;
  var k:int;
  var o:int;
  var k:int;
  var n:ubyte_ptr;
  var n:ubyte_ptr;
  var n:ubyte_ptr;
  var u:byte_ptr;
  var n:ubyte_ptr;
  var n:ubyte_ptr;
  var s:byte_ptr;
  var s:byte_ptr;
  var n:ubyte_ptr;
  var k:int;
  var j:int_ptr;
  var i:ubyte_ptr;
  var i:ubyte_ptr;
  var k:int;
  var aa:double;
  var k:int;
  var k:int;
  var n:ubyte_ptr;
  var aa:double;
  var aa:double;
  var aa:double;
  var aa:double;
  var g:int;
  var k:int;
  var k:int;
  var k:int;
  var k:int;
  var g:int;
  var g:int;
  var h:int;
  var g:int;
  var k:int;
  var u:byte_ptr;
  var k:int;
  var r:int;
  var g:int;
  var r:int;
  var k:int;
  var r:int;
  var q:int;
  var r:int;
  var k:int;
  var r:int;
  var g:int;
  var o:int;
  var k:int;
  var k:int;
  var r:int;
  var g:int;
  var u:byte_ptr;
  var g:int;
  var u:byte_ptr;
  var r:int;
  var k:int;
  var v:int;
  var n:ubyte_ptr;
  var v:int;
  var j:int_ptr;
  var g:int;
  var r:int;
  var g:int;
  var k:int;
  var r:int;
  var u:byte_ptr;
  var u:byte_ptr;
  var q:int;
  var j:int_ptr;
  var g:int;
  var j:int_ptr;
  var j:int_ptr;
  g = g_a - 560;
  var w:int = g;
  if (w < g_c) { env_handle_stack_overflow() }
  g_a = w;
  label B_a:
  g[11]:int = 0;
  y = f_la(b);
  if (y > -1L) goto B_d;
  h = 1;
  i = 1600;
  b = -(b);
  y = f_la(b);
  goto B_c;
  label B_d:
  if (eqz(e & 2048)) goto B_e;
  h = 1;
  i = 1603;
  goto B_c;
  label B_e:
  i = select_if(1606, 1601, h = e & 1);
  label B_c:
  if ((y & 9218868437227405312L) != 9218868437227405312L) goto B_g;
  f_ea(a, 32, c, j = h + 3, e & -65537);
  f_ba(a, i, h);
  f_ba(a,
       select_if(select_if(1627, 1631, k = f >> 5 & 1),
                 select_if(1619, 1623, k),
                 b != b),
       3);
  f_ea(a, 32, c, j, e ^ 8192);
  goto B_f;
  label B_g:
  var l:int = g + 16;
  b = f_v(b, g + 44);
  b = b + b;
  if (b == 0.0) goto B_k;
  g[11]:int = (k = g[11]:int) + -1;
  m = f | 32;
  if (m != 97) goto B_j;
  goto B_h;
  label B_k:
  m = f | 32;
  if (m == 97) goto B_h;
  n = select_if(6, d, d < 0);
  o = g[11]:int;
  goto B_i;
  label B_j:
  g[11]:int = (o = k + -29);
  n = select_if(6, d, d < 0);
  b = b * 268435456.0;
  label B_i:
  var p:int = select_if(g + 48, g + 336, o < 0);
  q = p;
  loop L_l {
    if (eqz(b < 4294967296.0 & b >= 0.0)) goto B_n;
    k = i32_trunc_f64_u(b);
    goto B_m;
    label B_n:
    k = 0;
    label B_m:
    q[0]:int = k;
    q = q + 4;
    b = (b - f64_convert_i32_u(k)) * 1000000000.0;
    if (b != 0.0) continue L_l;
  }
  if (o >= 1) goto B_p;
  k = q;
  r = p;
  goto B_o;
  label B_p:
  r = p;
  loop L_q {
    o = select_if(o, 29, o < 29);
    k = q + -4;
    if (k < r) goto B_r;
    var z:long = i64_extend_i32_u(o);
    y = 0L;
    loop L_s {
      k[0]:int = 
        (y = (k[0]:uint << z) + (y & 4294967295L)) - 
        (y = y / 1000000000L) * 1000000000L;
      k = k + -4;
      if (k >= r) continue L_s;
    }
    k = i32_wrap_i64(y);
    if (eqz(k)) goto B_r;
    r = r + -4;
    r[0]:int = k;
    label B_r:
    loop L_u {
      k = q;
      if (k <= r) goto B_t;
      q = k + -4;
      if (eqz(q[0]:int)) continue L_u;
    }
    label B_t:
    g[11]:int = (o = g[11]:int - o);
    q = k;
    if (o > 0) continue L_q;
  }
  label B_o:
  if (o > -1) goto B_v;
  s = (n + 25) / 9 + 1;
  t = m == 102;
  loop L_w {
    j = select_if(9, 0 - o, o < -9);
    if (r < k) goto B_y;
    r = select_if(r, r + 4, r[0]:int);
    goto B_x;
    label B_y:
    u = 1000000000 >> j;
    v = -1 << j ^ -1;
    o = 0;
    q = r;
    loop L_z {
      q[0]:int = ((d = q[0]:int) >> j) + o;
      o = (d & v) * u;
      q = q + 4;
      if (q < k) continue L_z;
    }
    r = select_if(r, r + 4, r[0]:int);
    if (eqz(o)) goto B_x;
    k[0]:int = o;
    k = k + 4;
    label B_x:
    g[11]:int = (o = g[11]:int + j);
    q = select_if(p, r, t);
    k = select_if(q + (s << 2), k, k - q >> 2 > s);
    if (o < 0) continue L_w;
  }
  label B_v:
  q = 0;
  if (r >= k) goto B_aa;
  q = (p - r >> 2) * 9;
  o = 10;
  d = r[0]:int;
  if (d < 10) goto B_aa;
  loop L_ba {
    q = q + 1;
    if (d >= (o = o * 10)) continue L_ba;
  }
  label B_aa:
  o = n - select_if(0, q, m == 102) - (n != 0 & m == 103);
  if (o >= (k - p >> 2) * 9 + -9) goto B_ca;
  d = o + 9216;
  u = d / 9;
  j = (u << 2) + p + -4092;
  o = 10;
  d = d - u * 9;
  if (d > 7) goto B_da;
  loop L_ea {
    o = o * 10;
    d = d + 1;
    if (d != 8) continue L_ea;
  }
  label B_da:
  u = j[0];
  d = u - (v = u / o) * o;
  s = j + 4;
  if (s != k) goto B_ga;
  if (eqz(d)) goto B_fa;
  label B_ga:
  aa = 
    select_if(
      0.5,
      select_if(select_if(1.0, 1.5, d == (t = o >> 1)), 1.5, s == k),
      d < t);
  b = select_if(9007199254740994.0, 9007199254740992.0, v & 1);
  if (eqz(h)) goto B_ha;
  if (i[0] != 45) goto B_ha;
  aa = -(aa);
  b = -(b);
  label B_ha:
  j[0] = (d = u - d);
  if (b + aa == b) goto B_fa;
  j[0] = (q = d + o);
  if (q < 1000000000) goto B_ia;
  loop L_ja {
    j[0] = 0;
    j = j + -4;
    if (j >= r) goto B_ka;
    r = r + -4;
    r[0]:int = 0;
    label B_ka:
    j[0] = (q = j[0] + 1);
    if (q > 999999999) continue L_ja;
  }
  label B_ia:
  q = (p - r >> 2) * 9;
  o = 10;
  d = r[0]:int;
  if (d < 10) goto B_fa;
  loop L_la {
    q = q + 1;
    if (d >= (o = o * 10)) continue L_la;
  }
  label B_fa:
  o = j + 4;
  k = select_if(o, k, k > o);
  label B_ca:
  loop L_na {
    o = k;
    if (o > r) goto B_oa;
    t = 0;
    goto B_ma;
    label B_oa:
    k = o + -4;
    if (eqz(k[0]:int)) continue L_na;
  }
  t = 1;
  label B_ma:
  if (m == 103) goto B_qa;
  v = e & 8;
  goto B_pa;
  label B_qa:
  n = 
    select_if(q ^ -1, -1, d = (k = select_if(n, 1, n)) > q & q > -5) + k;
  f = select_if(-1, -2, d) + f;
  v = e & 8;
  if (v) goto B_pa;
  k = 9;
  if (eqz(t)) goto B_ra;
  k = 9;
  j = (o + -4)[0]:int;
  if (eqz(j)) goto B_ra;
  d = 10;
  k = 0;
  if (j % 10) goto B_ra;
  loop L_sa {
    k = k + 1;
    if (eqz(j % (d = d * 10))) continue L_sa;
  }
  label B_ra:
  d = (o - p >> 2) * 9 + -9;
  if ((f | 32) != 102) goto B_ta;
  v = 0;
  n = select_if(n, k = select_if(k = d - k, 0, k > 0), n < k);
  goto B_pa;
  label B_ta:
  v = 0;
  n = select_if(n, k = select_if(k = d + q - k, 0, k > 0), n < k);
  label B_pa:
  m = n | v;
  d = m != 0;
  u = f | 32;
  if (u != 102) goto B_va;
  k = select_if(q, 0, q > 0);
  goto B_ua;
  label B_va:
  if (
    l - (k = f_ha(i64_extend_i32_u(q + (k = q >> 31) ^ k), l)) > 1) goto B_wa;
  loop L_xa {
    k = k + -1;
    k[0]:byte = 48;
    if (l - k < 2) continue L_xa;
  }
  label B_wa:
  s = k + -2;
  s[0] = f;
  (k + -1)[0]:byte = select_if(45, 43, q < 0);
  k = l - s;
  label B_ua:
  f_ea(a, 32, c, j = h + n + d + k + 1, e);
  f_ba(a, i, h);
  f_ea(a, 48, c, j, e ^ 65536);
  if (u != 102) goto B_bb;
  u = g + 16 | 8;
  q = g + 16 | 9;
  d = select_if(p, r, r > p);
  r = d;
  loop L_cb {
    k = f_ha(r[0]:uint, q);
    if (r == d) goto B_eb;
    if (k <= g + 16) goto B_db;
    loop L_fb {
      k = k + -1;
      k[0]:byte = 48;
      if (k > g + 16) continue L_fb;
      goto B_db;
      unreachable;
    }
    unreachable;
    label B_eb:
    if (k != q) goto B_db;
    g[24]:byte = 48;
    k = u;
    label B_db:
    f_ba(a, k, q - k);
    r = r + 4;
    if (r <= p) continue L_cb;
  }
  if (eqz(m)) goto B_gb;
  f_ba(a, 1635, 1);
  label B_gb:
  if (r >= o) goto B_ab;
  if (n < 1) goto B_ab;
  loop L_hb {
    k = f_ha(r[0]:uint, q);
    if (k <= g + 16) goto B_ib;
    loop L_jb {
      k = k + -1;
      k[0]:byte = 48;
      if (k > g + 16) continue L_jb;
    }
    label B_ib:
    f_ba(a, k, select_if(n, 9, n < 9));
    k = n + -9;
    r = r + 4;
    if (r >= o) goto B_za;
    d = n > 9;
    n = k;
    if (d) continue L_hb;
    goto B_za;
    unreachable;
  }
  unreachable;
  label B_bb:
  if (n < 0) goto B_kb;
  u = select_if(o, r + 4, t);
  p = g + 16 | 8;
  o = g + 16 | 9;
  q = r;
  loop L_lb {
    k = f_ha(q[0]:uint, o);
    if (k != o) goto B_mb;
    g[24]:byte = 48;
    k = p;
    label B_mb:
    if (q == r) goto B_ob;
    if (k <= g + 16) goto B_nb;
    loop L_pb {
      k = k + -1;
      k[0]:byte = 48;
      if (k > g + 16) continue L_pb;
      goto B_nb;
      unreachable;
    }
    unreachable;
    label B_ob:
    f_ba(a, k, 1);
    k = k + 1;
    if (v) goto B_qb;
    if (n < 1) goto B_nb;
    label B_qb:
    f_ba(a, 1635, 1);
    label B_nb:
    f_ba(a, k, select_if(d = o - k, n, n > d));
    n = n - d;
    q = q + 4;
    if (q >= u) goto B_kb;
    if (n > -1) continue L_lb;
  }
  label B_kb:
  f_ea(a, 48, n + 18, 18, 0);
  f_ba(a, s, l - s);
  goto B_ya;
  label B_ab:
  k = n;
  label B_za:
  f_ea(a, 48, k + 9, 9, 0);
  label B_ya:
  f_ea(a, 32, c, j, e ^ 8192);
  goto B_f;
  label B_h:
  n = select_if(i + 9, i, q = f & 32);
  if (d > 11) goto B_rb;
  k = 12 - d;
  if (eqz(k)) goto B_rb;
  aa = 8.0;
  loop L_sb {
    aa = aa * 16.0;
    k = k + -1;
    if (k) continue L_sb;
  }
  if (n[0] != 45) goto B_tb;
  b = -(aa + -(b) - aa);
  goto B_rb;
  label B_tb:
  b = b + aa - aa;
  label B_rb:
  k = g[11]:int;
  k = f_ha(i64_extend_i32_u(k + (k = k >> 31) ^ k), l);
  if (k != l) goto B_ub;
  g[15]:byte = 48;
  k = g + 15;
  label B_ub:
  v = h | 2;
  r = g[11]:int;
  u = k + -2;
  u[0] = f + 15;
  (k + -1)[0]:byte = select_if(45, 43, r < 0);
  o = e & 8;
  r = g + 16;
  loop L_vb {
    k = r;
    if (eqz(abs(b) < 2147483648.0)) goto B_xb;
    r = i32_trunc_f64_s(b);
    goto B_wb;
    label B_xb:
    r = -2147483648;
    label B_wb:
    k[0]:byte = (r + 1584)[0]:ubyte | q;
    b = (b - f64_convert_i32_s(r)) * 16.0;
    r = k + 1;
    if (r - g + 16 != 1) goto B_yb;
    if (o) goto B_zb;
    if (d > 0) goto B_zb;
    if (b == 0.0) goto B_yb;
    label B_zb:
    k[1]:byte = 46;
    r = k + 2;
    label B_yb:
    if (b != 0.0) continue L_vb;
  }
  if (eqz(d)) goto B_bc;
  if (r - g + 16 + -2 >= d) goto B_bc;
  k = d + l - u + 2;
  goto B_ac;
  label B_bc:
  k = l - g + 16 - u + r;
  label B_ac:
  f_ea(a, 32, c, j = k + v, e);
  f_ba(a, n, v);
  f_ea(a, 48, c, j, e ^ 65536);
  f_ba(a, g + 16, r = r - g + 16);
  f_ea(a, 48, k - r + (q = l - u), 0, 0);
  f_ba(a, u, q);
  f_ea(a, 32, c, j, e ^ 8192);
  label B_f:
  var x:int = g + 560;
  if (x < g_c) { env_handle_stack_overflow() }
  g_a = x;
  label B_cc:
  return select_if(c, j, j < c);
}

function f_ka(a:double_ptr, b:int_ptr) {
  var c:{ a:long, b:long }
  b[0] = (c = b[0] + 15 & -16) + 16;
  a[0] = f_y(c.a, c.b);
}

function f_la(a:double):long {
  return i64_reinterpret_f64(a)
}

export function malloc(a:int):int {
  var d:{ a:int, b:int, c:int }
  var e:int;
  var g:int;
  var g:int;
  var g:int;
  var g:int;
  var d:{ a:int, b:int, c:int }
  var h:int;
  var e:int;
  var e:int;
  var e:int;
  var g:int;
  var e:int;
  var g:int;
  var e:int;
  var e:int;
  var e:int;
  var g:int;
  var f:int;
  var e:int;
  var f:int;
  var c:int_ptr;
  var g:int;
  var f:int;
  var f:int;
  var e:int;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var e:int;
  var d:{ a:int, b:int, c:int }
  var f:int;
  var g:int;
  var i:int;
  var d:{ a:int, b:int, c:int }
  var e:int;
  var g:int;
  var c:int_ptr;
  var c:int_ptr;
  var d:{ a:int, b:int, c:int }
  var d:{ a:int, b:int, c:int }
  var d:{ a:int, b:int, c:int }
  var e:int;
  var e:int;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var e:int;
  var f:int;
  var g:int;
  var e:int;
  var g:int;
  var e:int;
  var g:int;
  var e:int;
  var e:int;
  var e:int;
  var f:int;
  var d:{ a:int, b:int, c:int }
  var f:int;
  var g:int;
  var g:int;
  var d:{ a:int, b:int, c:int }
  var g:int;
  var e:int;
  var g:int;
  var e:int;
  var f:int;
  var g:int;
  var f:int;
  var f:int;
  var i:int;
  var f:int;
  var f:int;
  var f:int;
  var i:int;
  var i:int;
  var f:int;
  var g:int;
  var f:int;
  var f:int;
  var g:int;
  var i:int;
  var g:int;
  var i:int;
  var i:int;
  var l:int_ptr;
  var h:int;
  var d:{ a:int, b:int, c:int }
  var g:int;
  var g:int;
  var e:int;
  var g:int;
  var d:{ a:int, b:int, c:int }
  var d:{ a:int, b:int, c:int }
  var l:int_ptr;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var l:int_ptr;
  var l:int_ptr;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var c:int_ptr;
  var g:int;
  var c:int_ptr;
  var e:int;
  var c:int_ptr;
  var e:int;
  var e:int;
  var e:int;
  var c:int_ptr;
  var e:int;
  var f:int;
  var c:int_ptr;
  var f:int;
  var e:int;
  var e:int;
  var i:int;
  var l:int_ptr;
  var h:int;
  var e:int;
  var f:int;
  var e:int;
  var f:int;
  var e:int;
  var e:int;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var c:int_ptr;
  var g:int;
  var e:int;
  var c:int_ptr;
  var g:int;
  var f:int;
  var i:int;
  var f:int;
  var e:int;
  var e:int;
  var i:int;
  var g:int;
  var d:{ a:int, b:int, c:int }
  var i:int;
  var i:int;
  var f:int;
  var i:int;
  var i:int;
  var i:int;
  var f:int;
  var f:int;
  var i:int;
  var e:int;
  var i:int;
  var i:int;
  var e:int;
  var f:int;
  var e:int;
  var f:int;
  var f:int;
  var c:int_ptr;
  var d:{ a:int, b:int, c:int }
  var d:{ a:int, b:int, c:int }
  var g:int;
  var g:int;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var f:int;
  var g:int;
  var e:int;
  var g:int;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var e:int;
  var e:int;
  var e:int;
  var f:int;
  var d:{ a:int, b:int, c:int }
  var f:int;
  var d:{ a:int, b:int, c:int }
  var d:{ a:int, b:int, c:int }
  var g:int;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var b:int;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var c:int_ptr;
  var e:int;
  var i:int;
  var d:{ a:int, b:int, c:int }
  var e:int;
  var g:int;
  var i:int;
  var j:int_ptr;
  var g:int;
  var j:int_ptr;
  var e:int;
  var e:int;
  var g:int;
  var e:int;
  var g:int;
  var e:int;
  var f:int;
  var i:int;
  var e:int;
  var f:int;
  var i:int;
  var f:int;
  var e:int;
  var f:int;
  var c:int_ptr;
  var d:{ a:int, b:int, c:int }
  var c:int_ptr;
  var e:int;
  var c:int_ptr;
  var g:int;
  var e:int;
  var g:int;
  var c:int_ptr;
  var f:int;
  var c:int_ptr;
  var f:int;
  var l:int_ptr;
  var c:int_ptr;
  var c:int_ptr;
  var f:int;
  var f:int;
  var d:{ a:int, b:int, c:int }
  var c:int_ptr;
  var h:int;
  var c:int_ptr;
  var e:int;
  var e:int;
  var e:int;
  var e:int;
  var c:int_ptr;
  var c:int_ptr;
  var f:int;
  var i:int;
  var i:int;
  var f:int;
  var f:int;
  var f:int;
  var c:int_ptr;
  var d:{ a:int, b:int, c:int }
  var c:int_ptr;
  var e:int;
  var f:int;
  var f:int;
  var f:int;
  var c:int_ptr;
  var f:int;
  var e:int;
  var e:int;
  var e:int;
  var g:int;
  var c:int_ptr;
  var f:int;
  var f:int;
  var f:int;
  var e:int;
  var e:int;
  var g:int;
  var f:int;
  var f:int;
  var e:int;
  var g:int;
  var e:int;
  var i:int;
  var c:int_ptr;
  var e:int;
  var e:int;
  var e:int;
  var c:int_ptr;
  var g:int;
  var e:int;
  var f:int;
  var f:int;
  var f:int;
  var f:int;
  var f:int;
  var c:int_ptr;
  var g:int;
  var g:int;
  var e:int;
  var g:int;
  var g:int;
  var e:int;
  var f:int;
  var c:int_ptr;
  var f:int;
  var f:int;
  var f:int;
  var l:int_ptr;
  var d:{ a:int, b:int, c:int }
  var g:int;
  var g:int;
  var g:int;
  var f:int;
  var l:int_ptr;
  var d:{ a:int, b:int, c:int }
  var l:int_ptr;
  var d:{ a:int, b:int, c:int }
  var e:int;
  var f:int;
  var g:int;
  var g:int;
  var f:int;
  var g:int;
  var g:int;
  var g:int;
  var f:int;
  var e:int;
  var e:int;
  var e:int;
  var f:int;
  var f:int;
  var c:int_ptr;
  var e:int;
  var i:int;
  var c:int_ptr;
  var d:{ a:int, b:int, c:int }
  var c:int_ptr;
  var j:int_ptr;
  var d:{ a:int, b:int, c:int }
  var e:int;
  var i:int;
  var d:{ a:int, b:int, c:int }
  var c:int_ptr;
  var d:{ a:int, b:int, c:int }
  var d:{ a:int, b:int, c:int }
  var c:int_ptr;
  var f:int;
  var f:int;
  var c:int_ptr;
  var f:int;
  var i:int;
  var f:int;
  var e:int;
  var f:int;
  var e:int;
  var c:int_ptr;
  var c:int_ptr;
  var e:int;
  var f:int;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var f:int;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var e:int;
  var d:{ a:int, b:int, c:int }
  var c:int_ptr;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var c:int_ptr;
  var c:int_ptr;
  var d:{ a:int, b:int, c:int }
  var i:int;
  var j:int_ptr;
  var f:int;
  var d:{ a:int, b:int, c:int }
  var e:int;
  var f:int;
  var e:int;
  var c:int_ptr;
  var c:int_ptr;
  var d:{ a:int, b:int, c:int }
  var j:int_ptr;
  var j:int_ptr;
  var f:int;
  var c:int_ptr;
  var c:int_ptr;
  var c:int_ptr;
  var j:int_ptr;
  var f:int;
  var e:int;
  var c:int_ptr;
  var e:int;
  var e:int;
  var c:int_ptr;
  var f:int;
  var e:int;
  var c:int_ptr;
  var e:int;
  var e:int;
  var c:int_ptr;
  var h:int;
  var f:int;
  var h:int;
  var f:int;
  var f:int;
  var g:int;
  var g:int;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var e:int;
  var d:{ a:int, b:int, c:int }
  var e:int;
  var g:int;
  var e:int;
  var g:int;
  var g:int;
  var g:int;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var d:{ a:int, b:int, c:int }
  var d:{ a:int, b:int, c:int }
  var d:{ a:int, b:int, c:int }
  var d:{ a:int, b:int, c:int }
  var f:int;
  var f:int;
  var d:{ a:int, b:int, c:int }
  var e:int;
  var f:int;
  var e:int;
  var e:int;
  var g:int;
  var e:int;
  var g:int;
  var e:int;
  var f:int;
  var e:int;
  var f:int;
  var i:int;
  var d:{ a:int, b:int, c:int }
  var g:int;
  var g:int;
  var d:{ a:int, b:int, c:int }
  var e:int;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var f:int;
  var d:{ a:int, b:int, c:int }
  var e:int;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var f:int;
  var i:int;
  var f:int;
  var i:int;
  var g:int;
  var g:int;
  var d:{ a:int, b:int, c:int }
  var g:int;
  var g:int;
  var g:int;
  var g:int;
  var c:int_ptr;
  var f:int;
  var f:int;
  var f:int;
  var i:int;
  var i:int;
  var l:int_ptr;
  var f:int;
  var e:int;
  var g:int;
  var g:int;
  var g:int;
  var e:int;
  var i:int;
  var i:int;
  var i:int;
  var i:int;
  var c:int_ptr;
  var f:int;
  var i:int;
  var g:int;
  var f:int;
  var i:int;
  var e:int;
  var i:int;
  var i:int;
  var e:int;
  var i:int;
  var e:int;
  var i:int;
  var c:int_ptr;
  var c:int_ptr;
  var c:int_ptr;
  var g:int;
  var f:int;
  var g:int;
  var f:int;
  var g:int;
  var e:int;
  var g:int;
  var e:int;
  var e:int;
  var e:int;
  var g:int;
  var c:int_ptr;
  var g:int;
  var c:int_ptr;
  var g:int;
  var g:int;
  var g:int;
  var g:int;
  var f:int;
  var f:int;
  var g:int;
  var f:int;
  var c:int_ptr;
  var e:int;
  var e:int;
  var f:int;
  var f:int;
  var i:int;
  var g:int;
  var e:int;
  var e:int;
  var g:int;
  var c:int_ptr;
  var g:int;
  var f:int;
  var g:int;
  var c:int_ptr;
  var g:int;
  var f:int;
  var i:int;
  var f:int;
  var i:int;
  var e:int;
  var e:int;
  var g:int;
  var e:int;
  var e:int;
  var e:int;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var g:int;
  var d:{ a:int, b:int, c:int }
  var g:int;
  var g:int;
  var g:int;
  var d:{ a:int, b:int, c:int }
  var g:int;
  var l:int_ptr;
  var g:int;
  var e:int;
  var g:int;
  var e:int;
  var e:int;
  var e:int;
  var g:int;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var d:{ a:int, b:int, c:int }
  var d:{ a:int, b:int, c:int }
  var g:int;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var l:int_ptr;
  var i:int;
  var i:int;
  var f:int;
  var f:int;
  var h:int;
  var e:int;
  var l:int_ptr;
  var l:int_ptr;
  var i:int;
  var f:int;
  var f:int;
  var f:int;
  var l:int_ptr;
  var i:int;
  var f:int;
  var f:int;
  var i:int;
  var f:int;
  var f:int;
  var g:int;
  var i:int;
  var g:int;
  var d:{ a:int, b:int, c:int }
  var i:int;
  var i:int;
  var d:{ a:int, b:int, c:int }
  var i:int;
  var d:{ a:int, b:int, c:int }
  var f:int;
  var g:int;
  var f:int;
  var g:int;
  var g:int;
  var g:int;
  var g:int;
  var e:int;
  var g:int;
  var e:int;
  var g:int;
  var e:int;
  var f:int;
  var e:int;
  var f:int;
  var f:int;
  var f:int;
  var e:int;
  var g:int;
  var e:int;
  var g:int;
  var e:int;
  var e:int;
  var e:int;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var d:{ a:int, b:int, c:int }
  var e:int;
  var d:{ a:int, b:int, c:int }
  var g:int;
  var f:int;
  var f:int;
  var h:int;
  var h:int;
  var d:{ a:int, b:int, c:int }
  var e:int;
  var f:int;
  var f:int;
  var e:int;
  var g:int;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var e:int;
  var g:int;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var c:int_ptr;
  var d:{ a:int, b:int, c:int }
  var c:int_ptr;
  var f:int;
  var f:int;
  var e:int;
  var f:int;
  var f:int;
  var f:int;
  var f:int;
  var e:int;
  var f:int;
  var e:int;
  var f:int;
  var f:int;
  var f:int;
  var e:int;
  var f:int;
  var i:int;
  var k:int_ptr;
  var f:int;
  var f:int;
  var i:int;
  var i:int;
  var j:int_ptr;
  var g:int;
  var k:int_ptr;
  var k:int_ptr;
  var f:int;
  var i:int;
  var i:int;
  var i:int;
  var k:int_ptr;
  var f:int;
  var i:int;
  var i:int;
  var f:int;
  var i:int;
  var i:int;
  var e:int;
  var f:int;
  var e:int;
  var d:{ a:int, b:int, c:int }
  var f:int;
  var f:int;
  var d:{ a:int, b:int, c:int }
  var f:int;
  var d:{ a:int, b:int, c:int }
  var g:int;
  var e:int;
  var g:int;
  var e:int;
  var e:int;
  var h:int;
  var h:int;
  var i:int;
  var i:int;
  var i:int;
  var c:int_ptr;
  var i:int;
  var c:int_ptr;
  var d:{ a:int, b:int, c:int }
  var d:{ a:int, b:int, c:int }
  var d:{ a:int, b:int, c:int }
  var i:int;
  var d:{ a:int, b:int, c:int }
  var i:int;
  var g:int;
  var e:int;
  var f:int;
  var b:int;
  b = g_a - 16;
  var m:int = b;
  if (m < g_c) { env_handle_stack_overflow() }
  g_a = m;
  label B_a:
  if (a > 244) goto B_n;
  c = d_c[17]:int;
  a = c >> (e = (d = select_if(16, a + 11 & -8, a < 11)) >> 3);
  if (eqz(a & 3)) goto B_o;
  d = ((a ^ -1) & 1) + e;
  f = d << 3;
  e = (f + 2164)[0]:int;
  a = e + 8;
  g = e[2]:int;
  if (g != (f = f + 2156)) goto B_q;
  d_c[17]:int = c & -2 << d;
  goto B_p;
  label B_q:
  d_c[21]:int > g;
  g[3]:int = f;
  f[2]:int = g;
  label B_p:
  e[1]:int = (g = d << 3) | 3;
  e = e + g;
  e[1]:int = e[1]:int | 1;
  goto B_c;
  label B_o:
  if (d <= (h = d_c[19]:int)) goto B_m;
  if (eqz(a)) goto B_r;
  a = a << e & ((a = 2 << e) | 0 - a);
  a = (a & 0 - a) + -1;
  e = a >> (a = a >> 12 & 16);
  g = e >> 5 & 8;
  g = 
    ((((g | a) | (e = (a = e >> g) >> 2 & 4)) | (e = (a = a >> e) >> 1 & 2)) | 
     (e = (a = a >> e) >> 1 & 1)) + 
    (a >> e);
  f = g << 3;
  e = (f + 2164)[0]:int;
  a = e[2]:int;
  if (a != (f = f + 2156)) goto B_t;
  d_c[17]:int = (c = c & -2 << g);
  goto B_s;
  label B_t:
  d_c[21]:int > a;
  a[3]:int = f;
  f[2]:int = a;
  label B_s:
  a = e + 8;
  e[1]:int = d | 3;
  f = e + d;
  f[1]:int = (g = (i = g << 3) - d) | 1;
  (e + i)[0]:int = g;
  if (eqz(h)) goto B_u;
  i = h >> 3;
  d = (i << 3) + 2156;
  e = d_c[22]:int;
  if (c & (i = 1 << i)) goto B_w;
  d_c[17]:int = c | i;
  i = d;
  goto B_v;
  label B_w:
  i = d.c;
  label B_v:
  d.c = e;
  i[3]:int = e;
  e[3]:int = d;
  e[2]:int = i;
  label B_u:
  d_c[22]:int = f;
  d_c[19]:int = g;
  goto B_c;
  label B_r:
  j = d_c[18]:int;
  if (eqz(j)) goto B_m;
  a = (j & 0 - j) + -1;
  e = a >> (a = a >> 12 & 16);
  g = e >> 5 & 8;
  f = 
    ((((((g | a) | (e = (a = e >> g) >> 2 & 4)) | (e = (a = a >> e) >> 1 & 2)) | 
       (e = (a = a >> e) >> 1 & 1)) + 
      (a >> e) << 
      2) + 
     2420)[0]:int;
  e = (f[1]:int & -8) - d;
  g = f;
  loop L_y {
    a = g[4]:int;
    if (a) goto B_z;
    a = (g + 20)[0]:int;
    if (eqz(a)) goto B_x;
    label B_z:
    g = (a[1]:int & -8) - d;
    e = select_if(g, e, g = g < e);
    f = select_if(a, f, g);
    g = a;
    continue L_y;
    unreachable;
  }
  unreachable;
  label B_x:
  k = f[6]:int;
  i = f[3]:int;
  if (i == f) goto B_aa;
  if (d_c[21]:int > (a = f[2]:int)) goto B_ba;
  a[3]:int != f;
  label B_ba:
  a[3]:int = i;
  i[2]:int = a;
  goto B_d;
  label B_aa:
  g = f + 20;
  a = g[0]:int;
  if (a) goto B_ca;
  a = f[4]:int;
  if (eqz(a)) goto B_l;
  g = f + 16;
  label B_ca:
  loop L_da {
    l = g;
    i = a;
    g = i + 20;
    a = g[0]:int;
    if (a) continue L_da;
    g = i + 16;
    a = i[4]:int;
    if (a) continue L_da;
  }
  l[0] = 0;
  goto B_d;
  label B_n:
  d = -1;
  if (a > -65) goto B_m;
  a = a + 11;
  d = a & -8;
  h = d_c[18]:int;
  if (eqz(h)) goto B_m;
  l = 0;
  a = a >> 8;
  if (eqz(a)) goto B_ea;
  l = 31;
  if (d > 16777215) goto B_ea;
  a = a << (e = a + 1048320 >> 16 & 8);
  g = a << (a = a + 520192 >> 16 & 4);
  a = ((g << (g = g + 245760 >> 16 & 2)) >> 15) - ((a | e) | g);
  l = (a << 1 | (d >> a + 21 & 1)) + 28;
  label B_ea:
  g = 0 - d;
  e = ((l << 2) + 2420)[0]:int;
  if (e) goto B_ia;
  a = 0;
  i = 0;
  goto B_ha;
  label B_ia:
  f = d << select_if(0, 25 - (l >> 1), l == 31);
  a = 0;
  i = 0;
  loop L_ja {
    c = (e[1]:int & -8) - d;
    if (c >= g) goto B_ka;
    g = c;
    i = e;
    if (c) goto B_ka;
    g = 0;
    i = e;
    a = e;
    goto B_ga;
    label B_ka:
    a = select_if(select_if(a,
                            c = (e + 20)[0]:int,
                            c == (e = (e + (f >> 29 & 4) + 16)[0]:int)),
                  a,
                  c);
    f = f << (e != 0);
    if (e) continue L_ja;
  }
  label B_ha:
  if (a | i) goto B_la;
  a = 2 << l;
  a = (a | 0 - a) & h;
  if (eqz(a)) goto B_m;
  a = (a & 0 - a) + -1;
  e = a >> (a = a >> 12 & 16);
  f = e >> 5 & 8;
  a = 
    ((((((f | a) | (e = (a = e >> f) >> 2 & 4)) | (e = (a = a >> e) >> 1 & 2)) | 
       (e = (a = a >> e) >> 1 & 1)) + 
      (a >> e) << 
      2) + 
     2420)[0]:int;
  label B_la:
  if (eqz(a)) goto B_fa;
  label B_ga:
  loop L_ma {
    c = (a[1]:int & -8) - d;
    f = c < g;
    e = a[4]:int;
    if (e) goto B_na;
    e = (a + 20)[0]:int;
    label B_na:
    g = select_if(c, g, f);
    i = select_if(a, i, f);
    a = e;
    if (e) continue L_ma;
  }
  label B_fa:
  if (eqz(i)) goto B_m;
  if (g >= d_c[19]:int - d) goto B_m;
  l = i[6]:int;
  f = i[3]:int;
  if (f == i) goto B_oa;
  if (d_c[21]:int > (a = i[2]:int)) goto B_pa;
  a[3]:int != i;
  label B_pa:
  a[3]:int = f;
  f[2]:int = a;
  goto B_e;
  label B_oa:
  e = i + 20;
  a = e[0]:int;
  if (a) goto B_qa;
  a = i[4]:int;
  if (eqz(a)) goto B_k;
  e = i + 16;
  label B_qa:
  loop L_ra {
    c = e;
    f = a;
    e = f + 20;
    a = e[0]:int;
    if (a) continue L_ra;
    e = f + 16;
    a = f[4]:int;
    if (a) continue L_ra;
  }
  c[0] = 0;
  goto B_e;
  label B_m:
  a = d_c[19]:int;
  if (a < d) goto B_sa;
  e = d_c[22]:int;
  g = a - d;
  if (g < 16) goto B_ua;
  d_c[19]:int = g;
  d_c[22]:int = (f = e + d);
  f[1]:int = g | 1;
  (e + a)[0]:int = g;
  e[1]:int = d | 3;
  goto B_ta;
  label B_ua:
  d_c[22]:int = 0;
  d_c[19]:int = 0;
  e[1]:int = a | 3;
  a = e + a;
  a[1]:int = a[1]:int | 1;
  label B_ta:
  a = e + 8;
  goto B_c;
  label B_sa:
  f = d_c[20]:int;
  if (f <= d) goto B_va;
  d_c[20]:int = (e = f - d);
  d_c[23]:int = (g = (a = d_c[23]:int) + d);
  g[1]:int = e | 1;
  a[1]:int = d | 3;
  a = a + 8;
  goto B_c;
  label B_va:
  if (eqz(d_c[135]:int)) goto B_xa;
  e = d_c[137]:int;
  goto B_wa;
  label B_xa:
  d_c[138]:long@4 = -1L;
  d_c[136]:long@4 = 17592186048512L;
  d_c[135]:int = (b + 12 & -16) ^ 1431655768;
  d_c[140]:int = 0;
  d_c[128]:int = 0;
  e = 4096;
  label B_wa:
  a = 0;
  c = e + (h = d + 47);
  i = c & (l = 0 - e);
  if (i <= d) goto B_c;
  a = 0;
  e = d_c[127]:int;
  if (eqz(e)) goto B_ya;
  g = d_c[125]:int;
  j = g + i;
  if (j <= g) goto B_c;
  if (j > e) goto B_c;
  label B_ya:
  if (d_c[512]:ubyte & 4) goto B_h;
  e = d_c[23]:int;
  if (eqz(e)) goto B_bb;
  a = 2564;
  loop L_cb {
    g = a[0]:int;
    if (g > e) goto B_db;
    if (g + a[1]:int > e) goto B_ab;
    label B_db:
    a = a[2]:int;
    if (a) continue L_cb;
  }
  label B_bb:
  f = f_oa(0);
  if (f == -1) goto B_i;
  c = i;
  a = d_c[136]:int;
  e = a + -1;
  if (eqz(e & f)) goto B_eb;
  c = i - f + (e + f & 0 - a);
  label B_eb:
  if (c <= d) goto B_i;
  if (c > 2147483646) goto B_i;
  a = d_c[127]:int;
  if (eqz(a)) goto B_fb;
  e = d_c[125]:int;
  g = e + c;
  if (g <= e) goto B_i;
  if (g > a) goto B_i;
  label B_fb:
  a = f_oa(c);
  if (a != f) goto B_za;
  goto B_g;
  label B_ab:
  c = c - f & l;
  if (c > 2147483646) goto B_i;
  f = f_oa(c);
  if (f == a[0]:int + a[1]:int) goto B_j;
  a = f;
  label B_za:
  if (d + 48 <= c) goto B_gb;
  if (a == -1) goto B_gb;
  e = h - c + (e = d_c[137]:int) & 0 - e;
  if (e <= 2147483646) goto B_hb;
  f = a;
  goto B_g;
  label B_hb:
  if (f_oa(e) == -1) goto B_ib;
  c = e + c;
  f = a;
  goto B_g;
  label B_ib:
  f_oa(0 - c);
  goto B_i;
  label B_gb:
  f = a;
  if (a != -1) goto B_g;
  goto B_i;
  label B_l:
  i = 0;
  goto B_d;
  label B_k:
  f = 0;
  goto B_e;
  label B_j:
  if (f != -1) goto B_g;
  label B_i:
  d_c[128]:int = d_c[128]:int | 4;
  label B_h:
  if (i > 2147483646) goto B_f;
  f = f_oa(i);
  if (f >= (a = f_oa(0))) goto B_f;
  if (f == -1) goto B_f;
  if (a == -1) goto B_f;
  c = a - f;
  if (c <= d + 40) goto B_f;
  label B_g:
  d_c[125]:int = (a = d_c[125]:int + c);
  if (a <= d_c[126]:int) goto B_jb;
  d_c[126]:int = a;
  label B_jb:
  e = d_c[23]:int;
  if (eqz(e)) goto B_nb;
  a = 2564;
  loop L_ob {
    if (f == (g = a[0]:int) + (i = a[1]:int)) goto B_mb;
    a = a[2]:int;
    if (a) continue L_ob;
    goto B_lb;
    unreachable;
  }
  unreachable;
  label B_nb:
  a = d_c[21]:int;
  if (eqz(a)) goto B_qb;
  if (f >= a) goto B_pb;
  label B_qb:
  d_c[21]:int = f;
  label B_pb:
  a = 0;
  d_c[130]:int = c;
  d_c[129]:int = f;
  d_c[25]:int = -1;
  d_c[26]:int = d_c[135]:int;
  d_c[132]:int = 0;
  loop L_rb {
    e = a << 3;
    (e + 2164)[0]:int = (g = e + 2156);
    (e + 2168)[0]:int = g;
    a = a + 1;
    if (a != 32) continue L_rb;
  }
  d_c[20]:int = 
    (g = (a = c + -40) - (e = select_if(-8 - f & 7, 0, f + 8 & 7)));
  d_c[23]:int = (e = f + e);
  e[1]:int = g | 1;
  (f + a)[1]:int = 40;
  d_c[24]:int = d_c[139]:int;
  goto B_kb;
  label B_mb:
  if (a[12]:ubyte & 8) goto B_lb;
  if (f <= e) goto B_lb;
  if (g > e) goto B_lb;
  a[1]:int = i + c;
  d_c[23]:int = (g = e + (a = select_if(-8 - e & 7, 0, e + 8 & 7)));
  d_c[20]:int = (a = (f = d_c[20]:int + c) - a);
  g[1]:int = a | 1;
  (e + f)[1]:int = 40;
  d_c[24]:int = d_c[139]:int;
  goto B_kb;
  label B_lb:
  if (f >= (i = d_c[21]:int)) goto B_sb;
  d_c[21]:int = f;
  i = f;
  label B_sb:
  g = f + c;
  a = 2564;
  loop L_ac {
    if (a[0]:int == g) goto B_zb;
    a = a[2]:int;
    if (a) continue L_ac;
    goto B_yb;
    unreachable;
  }
  unreachable;
  label B_zb:
  if (eqz(a[12]:ubyte & 8)) goto B_xb;
  label B_yb:
  a = 2564;
  loop L_bc {
    g = a[0]:int;
    if (g > e) goto B_cc;
    g = g + a[1]:int;
    if (g > e) goto B_wb;
    label B_cc:
    a = a[2]:int;
    continue L_bc;
    unreachable;
  }
  unreachable;
  label B_xb:
  a[0]:int = f;
  a[1]:int = a[1]:int + c;
  l = f + select_if(-8 - f & 7, 0, f + 8 & 7);
  l[1] = d | 3;
  f = g + select_if(-8 - g & 7, 0, g + 8 & 7);
  a = f - l - d;
  g = l + d;
  if (e != f) goto B_dc;
  d_c[23]:int = g;
  d_c[20]:int = (a = d_c[20]:int + a);
  g[1]:int = a | 1;
  goto B_ub;
  label B_dc:
  if (d_c[22]:int != f) goto B_ec;
  d_c[22]:int = g;
  d_c[19]:int = (a = d_c[19]:int + a);
  g[1]:int = a | 1;
  (g + a)[0]:int = a;
  goto B_ub;
  label B_ec:
  e = f[1]:int;
  if ((e & 3) != 1) goto B_fc;
  h = e & -8;
  if (e > 255) goto B_hc;
  d = f[3]:int;
  c = f[2]:int;
  if (c == (e = ((j = e >> 3) << 3) + 2156)) goto B_ic;
  i > c;
  label B_ic:
  if (d != c) goto B_jc;
  d_c[17]:int = d_c[17]:int & -2 << j;
  goto B_gc;
  label B_jc:
  if (d == e) goto B_kc;
  i > d;
  label B_kc:
  c[3] = d;
  d.c = c;
  goto B_gc;
  label B_hc:
  j = f[6]:int;
  c = f[3]:int;
  if (c == f) goto B_mc;
  if (i > (e = f[2]:int)) goto B_nc;
  e[3]:int != f;
  label B_nc:
  e[3]:int = c;
  c[2] = e;
  goto B_lc;
  label B_mc:
  e = f + 20;
  d = e[0]:int;
  if (d) goto B_oc;
  e = f + 16;
  d = e[0]:int;
  if (d) goto B_oc;
  c = 0;
  goto B_lc;
  label B_oc:
  loop L_pc {
    i = e;
    c = d;
    e = c + 20;
    d = e[0]:int;
    if (d) continue L_pc;
    e = c + 16;
    d = c[4];
    if (d) continue L_pc;
  }
  i[0]:int = 0;
  label B_lc:
  if (eqz(j)) goto B_gc;
  d = f[7]:int;
  e = (d << 2) + 2420;
  if (e[0]:int != f) goto B_rc;
  e[0]:int = c;
  if (c) goto B_qc;
  d_c[18]:int = d_c[18]:int & -2 << d;
  goto B_gc;
  label B_rc:
  (j + select_if(16, 20, j[4] == f))[0]:int = c;
  if (eqz(c)) goto B_gc;
  label B_qc:
  c[6] = j;
  e = f[4]:int;
  if (eqz(e)) goto B_sc;
  c[4] = e;
  e[6]:int = c;
  label B_sc:
  e = f[5]:int;
  if (eqz(e)) goto B_gc;
  (c + 20)[0]:int = e;
  e[6]:int = c;
  label B_gc:
  a = h + a;
  f = f + h;
  label B_fc:
  f[1]:int = f[1]:int & -2;
  g[1]:int = a | 1;
  (g + a)[0]:int = a;
  if (a > 255) goto B_tc;
  e = a >> 3;
  a = (e << 3) + 2156;
  d = d_c[17]:int;
  if (d & (e = 1 << e)) goto B_vc;
  d_c[17]:int = d | e;
  e = a;
  goto B_uc;
  label B_vc:
  e = a[2]:int;
  label B_uc:
  a[2]:int = g;
  e[3]:int = g;
  g[3]:int = a;
  g[2]:int = e;
  goto B_ub;
  label B_tc:
  e = 0;
  d = a >> 8;
  if (eqz(d)) goto B_wc;
  e = 31;
  if (a > 16777215) goto B_wc;
  d = d << (e = d + 1048320 >> 16 & 8);
  f = d << (d = d + 520192 >> 16 & 4);
  e = ((f << (f = f + 245760 >> 16 & 2)) >> 15) - ((d | e) | f);
  e = (e << 1 | (a >> e + 21 & 1)) + 28;
  label B_wc:
  g[7]:int = e;
  g[4]:long@4 = 0L;
  d = (e << 2) + 2420;
  f = d_c[18]:int;
  if (f & (i = 1 << e)) goto B_yc;
  d_c[18]:int = f | i;
  d.a = g;
  g[6]:int = d;
  goto B_xc;
  label B_yc:
  e = a << select_if(0, 25 - (e >> 1), e == 31);
  f = d.a;
  loop L_zc {
    d = f;
    if ((d.b & -8) == a) goto B_vb;
    f = e >> 29;
    e = e << 1;
    i = d + (f & 4) + 16;
    f = i[0]:int;
    if (f) continue L_zc;
  }
  i[0]:int = g;
  g[6]:int = d;
  label B_xc:
  g[3]:int = g;
  g[2]:int = g;
  goto B_ub;
  label B_wb:
  d_c[20]:int = 
    (l = (a = c + -40) - (i = select_if(-8 - f & 7, 0, f + 8 & 7)));
  d_c[23]:int = (i = f + i);
  i[1]:int = l | 1;
  (f + a)[1]:int = 40;
  d_c[24]:int = d_c[139]:int;
  i = select_if(e,
                a = g + select_if(39 - g & 7, 0, g + -39 & 7) + -47,
                a < e + 16);
  i[1]:int = 27;
  (i + 16)[0]:long@4 = d_c[131]:long@4;
  i[2]:long@4 = d_c[129]:long@4;
  d_c[131]:int = i + 8;
  d_c[130]:int = c;
  d_c[129]:int = f;
  d_c[132]:int = 0;
  a = i + 24;
  loop L_ad {
    a[1]:int = 7;
    f = a + 8;
    a = a + 4;
    if (g > f) continue L_ad;
  }
  if (i == e) goto B_kb;
  i[1]:int = i[1]:int & -2;
  e[1]:int = (c = i - e) | 1;
  i[0]:int = c;
  if (c > 255) goto B_bd;
  g = c >> 3;
  a = (g << 3) + 2156;
  f = d_c[17]:int;
  if (f & (g = 1 << g)) goto B_dd;
  d_c[17]:int = f | g;
  g = a;
  goto B_cd;
  label B_dd:
  g = a[2]:int;
  label B_cd:
  a[2]:int = e;
  g[3]:int = e;
  e[3]:int = a;
  e[2]:int = g;
  goto B_kb;
  label B_bd:
  a = 0;
  g = c >> 8;
  if (eqz(g)) goto B_ed;
  a = 31;
  if (c > 16777215) goto B_ed;
  g = g << (a = g + 1048320 >> 16 & 8);
  f = g << (g = g + 520192 >> 16 & 4);
  a = ((f << (f = f + 245760 >> 16 & 2)) >> 15) - ((g | a) | f);
  a = (a << 1 | (c >> a + 21 & 1)) + 28;
  label B_ed:
  e[4]:long@4 = 0L;
  (e + 28)[0]:int = a;
  g = (a << 2) + 2420;
  f = d_c[18]:int;
  if (f & (i = 1 << a)) goto B_gd;
  d_c[18]:int = f | i;
  g[0]:int = e;
  (e + 24)[0]:int = g;
  goto B_fd;
  label B_gd:
  a = c << select_if(0, 25 - (a >> 1), a == 31);
  f = g[0]:int;
  loop L_hd {
    g = f;
    if ((g[1]:int & -8) == c) goto B_tb;
    f = a >> 29;
    a = a << 1;
    i = g + (f & 4) + 16;
    f = i[0]:int;
    if (f) continue L_hd;
  }
  i[0]:int = e;
  (e + 24)[0]:int = g;
  label B_fd:
  e[3]:int = e;
  e[2]:int = e;
  goto B_kb;
  label B_vb:
  a = d.c;
  a[3]:int = g;
  d.c = g;
  g[6]:int = 0;
  g[3]:int = d;
  g[2]:int = a;
  label B_ub:
  a = l + 8;
  goto B_c;
  label B_tb:
  a = g[2]:int;
  a[3]:int = e;
  g[2]:int = e;
  (e + 24)[0]:int = 0;
  e[3]:int = g;
  e[2]:int = a;
  label B_kb:
  a = d_c[20]:int;
  if (a <= d) goto B_f;
  d_c[20]:int = (e = a - d);
  d_c[23]:int = (g = (a = d_c[23]:int) + d);
  g[1]:int = e | 1;
  a[1]:int = d | 3;
  a = a + 8;
  goto B_c;
  label B_f:
  errno_location()[0]:int = 48;
  a = 0;
  goto B_c;
  label B_e:
  if (eqz(l)) goto B_id;
  if (i != (a = ((e = i[7]:int) << 2) + 2420)[0]:int) goto B_kd;
  a[0]:int = f;
  if (f) goto B_jd;
  d_c[18]:int = (h = h & -2 << e);
  goto B_id;
  label B_kd:
  (l + select_if(16, 20, l[4] == i))[0]:int = f;
  if (eqz(f)) goto B_id;
  label B_jd:
  f[6]:int = l;
  a = i[4]:int;
  if (eqz(a)) goto B_ld;
  f[4]:int = a;
  a[6]:int = f;
  label B_ld:
  a = (i + 20)[0]:int;
  if (eqz(a)) goto B_id;
  (f + 20)[0]:int = a;
  a[6]:int = f;
  label B_id:
  if (g > 15) goto B_nd;
  i[1]:int = (a = g + d) | 3;
  a = i + a;
  a[1]:int = a[1]:int | 1;
  goto B_md;
  label B_nd:
  i[1]:int = d | 3;
  f = i + d;
  f[1]:int = g | 1;
  (f + g)[0]:int = g;
  if (g > 255) goto B_od;
  e = g >> 3;
  a = (e << 3) + 2156;
  g = d_c[17]:int;
  if (g & (e = 1 << e)) goto B_qd;
  d_c[17]:int = g | e;
  e = a;
  goto B_pd;
  label B_qd:
  e = a[2]:int;
  label B_pd:
  a[2]:int = f;
  e[3]:int = f;
  f[3]:int = a;
  f[2]:int = e;
  goto B_md;
  label B_od:
  e = g >> 8;
  if (e) goto B_sd;
  a = 0;
  goto B_rd;
  label B_sd:
  a = 31;
  if (g > 16777215) goto B_rd;
  e = e << (a = e + 1048320 >> 16 & 8);
  d = e << (e = e + 520192 >> 16 & 4);
  a = ((d << (d = d + 245760 >> 16 & 2)) >> 15) - ((e | a) | d);
  a = (a << 1 | (g >> a + 21 & 1)) + 28;
  label B_rd:
  f[7]:int = a;
  f[4]:long@4 = 0L;
  e = (a << 2) + 2420;
  if (h & (d = 1 << a)) goto B_vd;
  d_c[18]:int = h | d;
  e[0]:int = f;
  f[6]:int = e;
  goto B_ud;
  label B_vd:
  a = g << select_if(0, 25 - (a >> 1), a == 31);
  d = e[0]:int;
  loop L_wd {
    e = d;
    if ((e[1]:int & -8) == g) goto B_td;
    d = a >> 29;
    a = a << 1;
    c = e + (d & 4) + 16;
    d = c[0];
    if (d) continue L_wd;
  }
  c[0] = f;
  f[6]:int = e;
  label B_ud:
  f[3]:int = f;
  f[2]:int = f;
  goto B_md;
  label B_td:
  a = e[2]:int;
  a[3]:int = f;
  e[2]:int = f;
  f[6]:int = 0;
  f[3]:int = e;
  f[2]:int = a;
  label B_md:
  a = i + 8;
  goto B_c;
  label B_d:
  if (eqz(k)) goto B_xd;
  if (f != (a = ((g = f[7]:int) << 2) + 2420)[0]:int) goto B_zd;
  a[0]:int = i;
  if (i) goto B_yd;
  d_c[18]:int = j & -2 << g;
  goto B_xd;
  label B_zd:
  (k + select_if(16, 20, k[4] == f))[0]:int = i;
  if (eqz(i)) goto B_xd;
  label B_yd:
  i[6]:int = k;
  a = f[4]:int;
  if (eqz(a)) goto B_ae;
  i[4]:int = a;
  a[6]:int = i;
  label B_ae:
  a = (f + 20)[0]:int;
  if (eqz(a)) goto B_xd;
  (i + 20)[0]:int = a;
  a[6]:int = i;
  label B_xd:
  if (e > 15) goto B_ce;
  f[1]:int = (a = e + d) | 3;
  a = f + a;
  a[1]:int = a[1]:int | 1;
  goto B_be;
  label B_ce:
  f[1]:int = d | 3;
  g = f + d;
  g[1]:int = e | 1;
  (g + e)[0]:int = e;
  if (eqz(h)) goto B_de;
  i = h >> 3;
  d = (i << 3) + 2156;
  a = d_c[22]:int;
  i = 1 << i;
  if (i & c) goto B_fe;
  d_c[17]:int = i | c;
  i = d;
  goto B_ee;
  label B_fe:
  i = d.c;
  label B_ee:
  d.c = a;
  i[3]:int = a;
  a[3]:int = d;
  a[2]:int = i;
  label B_de:
  d_c[22]:int = g;
  d_c[19]:int = e;
  label B_be:
  a = f + 8;
  label B_c:
  var n:int = b + 16;
  if (n < g_c) { env_handle_stack_overflow() }
  g_a = n;
  label B_ge:
  return a;
}

export function free(a:int_ptr) {
  var c:int_ptr;
  var e:{ a:int, b:int, c:int }
  var h:int_ptr;
  var g:int_ptr;
  var h:int_ptr;
  var g:int_ptr;
  var g:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var g:int_ptr;
  var h:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var h:int_ptr;
  var h:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var h:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var e:{ a:int, b:int, c:int }
  var f:int_ptr;
  var e:{ a:int, b:int, c:int }
  var e:{ a:int, b:int, c:int }
  var f:int_ptr;
  var e:{ a:int, b:int, c:int }
  var e:{ a:int, b:int, c:int }
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var e:{ a:int, b:int, c:int }
  var e:{ a:int, b:int, c:int }
  var e:{ a:int, b:int, c:int }
  var f:int_ptr;
  var e:{ a:int, b:int, c:int }
  var f:int_ptr;
  var f:int_ptr;
  var e:{ a:int, b:int, c:int }
  var g:int_ptr;
  var h:int_ptr;
  var e:{ a:int, b:int, c:int }
  var f:int_ptr;
  var f:int_ptr;
  var e:{ a:int, b:int, c:int }
  var h:int_ptr;
  var h:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var h:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var e:{ a:int, b:int, c:int }
  var e:{ a:int, b:int, c:int }
  var e:{ a:int, b:int, c:int }
  var e:{ a:int, b:int, c:int }
  var e:{ a:int, b:int, c:int }
  var e:{ a:int, b:int, c:int }
  var e:{ a:int, b:int, c:int }
  var f:int_ptr;
  var f:int_ptr;
  var e:{ a:int, b:int, c:int }
  var f:int_ptr;
  var f:int_ptr;
  var f:int_ptr;
  var e:{ a:int, b:int, c:int }
  var e:{ a:int, b:int, c:int }
  var e:{ a:int, b:int, c:int }
  var f:int_ptr;
  var e:{ a:int, b:int, c:int }
  var e:{ a:int, b:int, c:int }
  var f:int_ptr;
  var f:int_ptr;
  var e:{ a:int, b:int, c:int }
  var e:{ a:int, b:int, c:int }
  var e:{ a:int, b:int, c:int }
  var e:{ a:int, b:int, c:int }
  if (eqz(a)) goto B_a;
  var b:int = a + -8;
  var d:{ a:int, b:int, c:int, d:int, e:int, f:int, g:int, h:int } = 
    b + (a = (c = (a + -4)[0]:int) & -8);
  if (c & 1) goto B_b;
  if (eqz(c & 3)) goto B_a;
  b = b - (c = b[0]:int);
  if (b < (e = d_c[21]:int)) goto B_a;
  a = c + a;
  if (d_c[22]:int == b) goto B_c;
  if (c > 255) goto B_d;
  f = b[3]:int;
  g = b[2]:int;
  if (g == (c = ((h = c >> 3) << 3) + 2156)) goto B_e;
  e > g;
  label B_e:
  if (f != g) goto B_f;
  d_c[17]:int = d_c[17]:int & -2 << h;
  goto B_b;
  label B_f:
  if (f == c) goto B_g;
  e > f;
  label B_g:
  g[3] = f;
  f[2] = g;
  goto B_b;
  label B_d:
  h = b[6]:int;
  f = b[3]:int;
  if (f == b) goto B_i;
  if (e > (c = b[2]:int)) goto B_j;
  c[3] != b;
  label B_j:
  c[3] = f;
  f[2] = c;
  goto B_h;
  label B_i:
  c = b + 20;
  e = c[0];
  if (e) goto B_k;
  c = b + 16;
  e = c[0];
  if (e) goto B_k;
  f = 0;
  goto B_h;
  label B_k:
  loop L_l {
    g = c;
    f = e;
    c = f + 20;
    e = c[0];
    if (e) continue L_l;
    c = f + 16;
    e = f[4];
    if (e) continue L_l;
  }
  g[0] = 0;
  label B_h:
  if (eqz(h)) goto B_b;
  e = b[7]:int;
  c = (e << 2) + 2420;
  if (c[0] != b) goto B_n;
  c[0] = f;
  if (f) goto B_m;
  d_c[18]:int = d_c[18]:int & -2 << e;
  goto B_b;
  label B_n:
  (h + select_if(16, 20, h[4] == b))[0]:int = f;
  if (eqz(f)) goto B_b;
  label B_m:
  f[6] = h;
  c = b[4]:int;
  if (eqz(c)) goto B_o;
  f[4] = c;
  c[6] = f;
  label B_o:
  c = b[5]:int;
  if (eqz(c)) goto B_b;
  (f + 20)[0]:int = c;
  c[6] = f;
  goto B_b;
  label B_c:
  c = d.b;
  if ((c & 3) != 3) goto B_b;
  d_c[19]:int = a;
  d.b = c & -2;
  b[1]:int = a | 1;
  (b + a)[0]:int = a;
  return ;
  label B_b:
  if (d <= b) goto B_a;
  c = d.b;
  if (eqz(c & 1)) goto B_a;
  if (c & 2) goto B_q;
  if (d_c[23]:int != d) goto B_r;
  d_c[23]:int = b;
  d_c[20]:int = (a = d_c[20]:int + a);
  b[1]:int = a | 1;
  if (b != d_c[22]:int) goto B_a;
  d_c[19]:int = 0;
  d_c[22]:int = 0;
  return ;
  label B_r:
  if (d_c[22]:int != d) goto B_s;
  d_c[22]:int = b;
  d_c[19]:int = (a = d_c[19]:int + a);
  b[1]:int = a | 1;
  (b + a)[0]:int = a;
  return ;
  label B_s:
  a = (c & -8) + a;
  if (c > 255) goto B_u;
  e = d.d;
  f = d.c;
  if (f == (c = ((d = c >> 3) << 3) + 2156)) goto B_v;
  d_c[21]:int > f;
  label B_v:
  if (e != f) goto B_w;
  d_c[17]:int = d_c[17]:int & -2 << d;
  goto B_t;
  label B_w:
  if (e == c) goto B_x;
  d_c[21]:int > e;
  label B_x:
  f[3] = e;
  e.c = f;
  goto B_t;
  label B_u:
  h = d.g;
  f = d.d;
  if (f == d) goto B_z;
  if (d_c[21]:int > (c = d.c)) goto B_aa;
  c[3] != d;
  label B_aa:
  c[3] = f;
  f[2] = c;
  goto B_y;
  label B_z:
  c = d + 20;
  e = c[0];
  if (e) goto B_ba;
  c = d + 16;
  e = c[0];
  if (e) goto B_ba;
  f = 0;
  goto B_y;
  label B_ba:
  loop L_ca {
    g = c;
    f = e;
    c = f + 20;
    e = c[0];
    if (e) continue L_ca;
    c = f + 16;
    e = f[4];
    if (e) continue L_ca;
  }
  g[0] = 0;
  label B_y:
  if (eqz(h)) goto B_t;
  e = d.h;
  c = (e << 2) + 2420;
  if (c[0] != d) goto B_ea;
  c[0] = f;
  if (f) goto B_da;
  d_c[18]:int = d_c[18]:int & -2 << e;
  goto B_t;
  label B_ea:
  (h + select_if(16, 20, h[4] == d))[0]:int = f;
  if (eqz(f)) goto B_t;
  label B_da:
  f[6] = h;
  c = d.e;
  if (eqz(c)) goto B_fa;
  f[4] = c;
  c[6] = f;
  label B_fa:
  c = d.f;
  if (eqz(c)) goto B_t;
  (f + 20)[0]:int = c;
  c[6] = f;
  label B_t:
  b[1]:int = a | 1;
  (b + a)[0]:int = a;
  if (b != d_c[22]:int) goto B_p;
  d_c[19]:int = a;
  return ;
  label B_q:
  d.b = c & -2;
  b[1]:int = a | 1;
  (b + a)[0]:int = a;
  label B_p:
  if (a > 255) goto B_ga;
  c = a >> 3;
  a = (c << 3) + 2156;
  e = d_c[17]:int;
  if (e & (c = 1 << c)) goto B_ia;
  d_c[17]:int = e | c;
  c = a;
  goto B_ha;
  label B_ia:
  c = a[2];
  label B_ha:
  a[2] = b;
  c[3] = b;
  b[3]:int = a;
  b[2]:int = c;
  return ;
  label B_ga:
  c = 0;
  e = a >> 8;
  if (eqz(e)) goto B_ja;
  c = 31;
  if (a > 16777215) goto B_ja;
  e = e << (c = e + 1048320 >> 16 & 8);
  f = e << (e = e + 520192 >> 16 & 4);
  c = ((f << (f = f + 245760 >> 16 & 2)) >> 15) - ((e | c) | f);
  c = (c << 1 | (a >> c + 21 & 1)) + 28;
  label B_ja:
  b[4]:long@4 = 0L;
  (b + 28)[0]:int = c;
  e = (c << 2) + 2420;
  f = d_c[18]:int;
  if (f & (d = 1 << c)) goto B_na;
  d_c[18]:int = f | d;
  e.a = b;
  (b + 24)[0]:int = e;
  goto B_ma;
  label B_na:
  c = a << select_if(0, 25 - (c >> 1), c == 31);
  f = e.a;
  loop L_oa {
    e = f;
    if ((e.b & -8) == a) goto B_la;
    f = c >> 29;
    c = c << 1;
    d = e + (f & 4) + 16;
    f = d.a;
    if (f) continue L_oa;
  }
  d.a = b;
  (b + 24)[0]:int = e;
  label B_ma:
  b[3]:int = b;
  b[2]:int = b;
  goto B_ka;
  label B_la:
  a = e.c;
  a[3] = b;
  e.c = b;
  (b + 24)[0]:int = 0;
  b[3]:int = e;
  b[2]:int = a;
  label B_ka:
  d_c[25]:int = (b = d_c[25]:int + -1);
  if (b) goto B_a;
  b = 2572;
  loop L_pa {
    a = b[0]:int;
    b = a + 8;
    if (a) continue L_pa;
  }
  d_c[25]:int = -1;
  label B_a:
}

function f_oa(a:int):int {
  var d:int;
  var b:int_ptr = f_f();
  var c:int = memory_size();
  d = b[0];
  a = d + (a + 3 & -4);
  if (a <= c << 16) goto B_a;
  if (env_emscripten_resize_heap(a)) goto B_a;
  errno_location()[0]:int = 48;
  return -1;
  label B_a:
  b[0] = a;
  return d;
}

function f_pa(a:int, b:int, c:int):int {
  var f:int;
  var e:int;
  var e:int;
  var e:int;
  var e:int;
  if (c < 512) goto B_a;
  env_emscripten_memcpy_big(a, b, c);
  return a;
  label B_a:
  var d:int = a + c;
  if ((b ^ a) & 3) goto B_c;
  if (c >= 1) goto B_e;
  c = a;
  goto B_d;
  label B_e:
  if (a & 3) goto B_f;
  c = a;
  goto B_d;
  label B_f:
  c = a;
  loop L_g {
    c[0]:byte = b[0]:ubyte;
    b = b + 1;
    c = c + 1;
    if (c >= d) goto B_d;
    if (c & 3) continue L_g;
  }
  label B_d:
  e = d & -4;
  if (e < 64) goto B_h;
  if (c > (f = e + -64)) goto B_h;
  loop L_i {
    c[0]:int = b[0]:int;
    c[1]:int = b[1]:int;
    c[2]:int = b[2]:int;
    c[3]:int = b[3]:int;
    c[4]:int = b[4]:int;
    c[5]:int = b[5]:int;
    c[6]:int = b[6]:int;
    c[7]:int = b[7]:int;
    c[8]:int = b[8]:int;
    c[9]:int = b[9]:int;
    c[10]:int = b[10]:int;
    c[11]:int = b[11]:int;
    c[12]:int = b[12]:int;
    c[13]:int = b[13]:int;
    c[14]:int = b[14]:int;
    c[15]:int = b[15]:int;
    b = b + 64;
    c = c + 64;
    if (c <= f) continue L_i;
  }
  label B_h:
  if (c >= e) goto B_b;
  loop L_j {
    c[0]:int = b[0]:int;
    b = b + 4;
    c = c + 4;
    if (c < e) continue L_j;
    goto B_b;
    unreachable;
  }
  unreachable;
  label B_c:
  if (d >= 4) goto B_k;
  c = a;
  goto B_b;
  label B_k:
  e = d + -4;
  if (e >= a) goto B_l;
  c = a;
  goto B_b;
  label B_l:
  c = a;
  loop L_m {
    c[0]:byte = b[0]:ubyte;
    c[1]:byte = b[1]:ubyte;
    c[2]:byte = b[2]:ubyte;
    c[3]:byte = b[3]:ubyte;
    b = b + 4;
    c = c + 4;
    if (c <= e) continue L_m;
  }
  label B_b:
  if (c >= d) goto B_n;
  loop L_o {
    c[0]:byte = b[0]:ubyte;
    b = b + 1;
    c = c + 1;
    if (c != d) continue L_o;
  }
  label B_n:
  return a;
}

function f_qa(a:{ a:byte, b:byte, c:byte, d:byte }, b:{ a:long, b:long, c:long, d:long }, c:int):int {
  var e:int;
  var f:int;
  if (eqz(c)) goto B_a;
  var d:{ a:int, b:int, c:int, d:int, e:int, f:int, g:int } = c + a;
  (d + -1)[0]:byte = b;
  a.a = b;
  if (c < 3) goto B_a;
  (d + -2)[0]:byte = b;
  a.b = b;
  (d + -3)[0]:byte = b;
  a.c = b;
  if (c < 7) goto B_a;
  (d + -4)[0]:byte = b;
  a.d = b;
  if (c < 9) goto B_a;
  d = a + (e = 0 - a & 3);
  d.a = (b = (b & 255) * 16843009);
  c = d + (e = c - e & -4);
  (c + -4)[0]:int = b;
  if (e < 9) goto B_a;
  d.c = b;
  d.b = b;
  (c + -8)[0]:int = b;
  (c + -12)[0]:int = b;
  if (e < 25) goto B_a;
  d.g = b;
  d.f = b;
  d.e = b;
  d.d = b;
  (c + -16)[0]:int = b;
  (c + -20)[0]:int = b;
  (c + -24)[0]:int = b;
  (c + -28)[0]:int = b;
  c = e - (f = (d & 4) | 24);
  if (c < 32) goto B_a;
  var g:long = i64_extend_i32_u(b);
  g = g << 32L | g;
  b = d + f;
  loop L_b {
    b.d = g;
    b.c = g;
    b.b = g;
    b.a = g;
    b = b + 32;
    c = c + -32;
    if (c > 31) continue L_b;
  }
  label B_a:
  return a;
}

function f_ra(a:int) {
}

function f_sa(a:int) {
}

function f_ta():int {
  f_ra(2612);
  return 2620;
}

function f_ua() {
  f_sa(2612)
}

function f_va(a:int):int {
  var b:int;
  a[74]:byte = (b = a[74]:ubyte) + -1 | b;
  b = a[0]:int;
  if (eqz(b & 8)) goto B_a;
  a[0]:int = b | 32;
  return -1;
  label B_a:
  a[1]:long@4 = 0L;
  a[7]:int = (b = a[11]:int);
  a[5]:int = b;
  a[4]:int = b + a[12]:int;
  return 0;
}

function f_wa(a:int, b:int, c:int):int {
  var d:int;
  var f:int;
  var e:int;
  var d:int;
  var d:int;
  var d:int;
  var e:int;
  var d:int;
  var d:int;
  var d:int;
  var d:int;
  var f:int;
  var e:int;
  d = c[4]:int;
  if (d) goto B_b;
  e = 0;
  if (f_va(c)) goto B_a;
  d = c[4]:int;
  label B_b:
  if (d - (f = c[5]:int) >= b) goto B_c;
  return call_indirect(c, a, b, c[9]:int);
  label B_c:
  var g:int = 0;
  if (c[75]:byte < 0) goto B_d;
  e = b;
  loop L_e {
    d = e;
    if (eqz(d)) goto B_d;
    if ((a + (e = d + -1))[0]:ubyte != 10) continue L_e;
  }
  e = call_indirect(c, a, d, c[9]:int);
  if (e < d) goto B_a;
  b = b - d;
  a = a + d;
  f = c[5]:int;
  g = d;
  label B_d:
  f_pa(f, a, b);
  c[5]:int = c[5]:int + b;
  e = g + b;
  label B_a:
  return e;
}

function f_xa(a:int):int {
  return 0
}

function f_ya(a:int, b:long, c:int):long {
  return 0L
}

function f_za(a:int, b:int):int {
  var c:int_ptr;
  var c:int_ptr;
  c = g_a - 16;
  var d:int = c;
  if (d < g_c) { env_handle_stack_overflow() }
  g_a = d;
  label B_a:
  c[3] = b;
  b = f_ia(d_ABCDEFGHIJKLMNOPQRSTUVWXYZab[154]:int, a, b);
  var e:int = c + 16;
  if (e < g_c) { env_handle_stack_overflow() }
  g_a = e;
  label B_c:
  return b;
}

function f_ab(a:int):int {
  return 1
}

function f_bb(a:int) {
}

function f_cb(a:ubyte_ptr):int {
  var d:int;
  var c:int;
  var c:int;
  var c:int;
  var d:int;
  var b:ubyte_ptr = a;
  if (eqz(a & 3)) goto B_b;
  if (a[0]) goto B_c;
  return a - a;
  label B_c:
  b = a;
  loop L_d {
    b = b + 1;
    if (eqz(b & 3)) goto B_b;
    if (eqz(b[0])) goto B_a;
    continue L_d;
    unreachable;
  }
  unreachable;
  label B_b:
  loop L_e {
    c = b;
    b = c + 4;
    d = c[0]:int;
    if (eqz(((d ^ -1) & d + -16843009) & -2139062144)) continue L_e;
  }
  if (d & 255) goto B_f;
  return c - a;
  label B_f:
  loop L_g {
    d = c[1]:ubyte;
    b = c + 1;
    c = b;
    if (d) continue L_g;
  }
  label B_a:
  return b - a;
}

export function setThrew(a:int, b:int) {
  if (d_c[402]:int) goto B_a;
  d_c[403]:int = b;
  d_c[402]:int = a;
  label B_a:
}

export function fflush(a:int_ptr):int {
  var c:int;
  var b:int;
  var c:int;
  if (eqz(a)) goto B_b;
  if (a[19] > -1) goto B_c;
  return f_fb(a);
  label B_c:
  b = f_ab(a);
  c = f_fb(a);
  if (eqz(b)) goto B_a;
  f_bb(a);
  return c;
  label B_b:
  c = 0;
  if (eqz(d_iB7Hh[98]:int)) goto B_d;
  c = fflush(d_iB7Hh[98]:int);
  label B_d:
  a = f_ta()[0]:int;
  if (eqz(a)) goto B_e;
  loop L_f {
    b = 0;
    if (a[19] < 0) goto B_g;
    b = f_ab(a);
    label B_g:
    if (a[5] <= a[7]) goto B_h;
    c = f_fb(a) | c;
    label B_h:
    if (eqz(b)) goto B_i;
    f_bb(a);
    label B_i:
    a = a[14];
    if (a) continue L_f;
  }
  label B_e:
  f_ua();
  label B_a:
  return c;
}

function f_fb(a:int):int {
  var c:int;
  if (a[5]:int <= a[7]:int) goto B_a;
  call_indirect(a, 0, 0, a[9]:int);
  if (a[5]:int) goto B_a;
  return -1;
  label B_a:
  var b:int = a[1]:int;
  if (b >= (c = a[2]:int)) goto B_b;
  call_indirect(a, i64_extend_i32_s(b - c), 1, a[10]:int);
  label B_b:
  a[7]:int = 0;
  a[2]:long = 0L;
  a[1]:long@4 = 0L;
  return 0;
}

export function set_stack_limit(a:int) {
  g_c = a
}

export function stackSave():int {
  return g_a
}

export function stackAlloc(a:int):int {
  var b:int;
  b = g_a - a & -16;
  var c:int = b;
  if (c < g_c) { env_handle_stack_overflow() }
  g_a = c;
  label B_a:
  return b;
}

export function stackRestore(a:int) {
  var b:int = a;
  if (b < g_c) { env_handle_stack_overflow() }
  g_a = b;
}

export function growWasmMemory(a:int):int {
  return memory_grow(a)
}

export function dynCall_iidiiii(a:int, b:int, c:double, d:int, e:int, f:int, g:int):int {
  return call_indirect(b, c, d, e, f, g, a)
}

export function dynCall_vii(a:int, b:int, c:int) {
  call_indirect(b, c, a)
}

export function dynCall_ii(a:int, b:int):int {
  return call_indirect(b, a)
}

export function dynCall_iiii(a:int, b:int, c:int, d:int):int {
  return call_indirect(b, c, d, a)
}

function f_pb(a:int, b:int, c:long, d:int):long {
  return call_indirect(b, c, d, a)
}

export function dynCall_jiji(a:int, b:int, c:int, d:int, e:int):int {
  var f:long = 
    f_pb(a, b, i64_extend_i32_u(c) | i64_extend_i32_u(d) << 32L, e);
  env_setTempRet0(i32_wrap_i64(f >> 32L));
  return i32_wrap_i64(f);
}

