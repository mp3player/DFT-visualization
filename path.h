#include <vector>
#include "util/Complex.hpp"

std::vector<Complex> pathes ={ 
    Complex(0, 50),
    Complex(0.019975013537430596, 50.51123825031108),
    Complex(0.1592017311657953, 52.0298728715403),
    Complex(0.5339545323826984, 54.51111747925488),
    Complex(1.2546207596059316, 57.88182602755194),
    Complex(2.422924709609385, 62.042686291707355),
    Complex(4.129348414261412, 66.87118593066484),
    Complex(6.4508078708934855, 72.22525091909789),
    Complex(9.448637638349004, 77.94743388649621),
    Complex(13.16692978028126, 83.86951209738483),
    Complex(17.63126516834218, 89.81734208445883),
    Complex(22.847866333522337, 95.61581074514501),
    Complex(28.80319157227644, 101.0937212636987),
    Complex(35.463980088169976, 106.0884565408631),
    Complex(42.77774780256799, 110.45027270065519),
    Complex(50.67372332728326, 114.0460902906708),
    Complex(59.06420368589673, 116.76267039896837),
    Complex(67.84629992117848, 118.50908631032299),
    Complex(76.90403394594485, 119.21842761352343),
    Complex(86.11074008102314, 118.848701843686),
    Complex(95.33171785455293, 117.3829277308603),
    Complex(104.42707696596806, 114.82844283875117),
    Complex(113.25471097310225, 111.21547574605384),
    Complex(121.67333333959974, 106.59505794016826),
    Complex(129.54550804786132, 101.03637235131826),
    Complex(136.74060707236413, 94.62365318089049),
    Complex(143.13762861742217, 87.4527647606427),
    Complex(148.62781311624695, 79.62759519403352),
    Complex(153.11699849515878, 71.25640325217562),
    Complex(156.52766202684862, 62.44825440678652),
    Complex(158.80060309909044, 53.309674168935466),
    Complex(159.89622925307802, 43.94163444997352),
    Complex(159.79541671841423, 34.436972034199115),
    Complex(158.49992619054308, 24.878318171893348),
    Complex(156.03236454740545, 15.336595612796815),
    Complex(152.43569336193602, 5.8701150418358194),
    Complex(147.7722952076228, -3.4757221575693764),
    Complex(142.12261864808636, -12.668132596738541),
    Complex(135.5834322263951, -21.686112219140533),
    Complex(128.2657265140585, -30.519112653255238),
    Complex(120.29231114703873, -39.16531310286925),
    Complex(111.79516059010564, -47.62958273384038),
    Complex(102.91256797849076, -55.92123871744802),
    Complex(93.78617066122138, -64.05171071108667),
    Complex(84.55791391781567, -72.03222344282801),
    Complex(75.36702067532583, -79.87160525735189),
    Complex(66.34703488567845, -87.57432220808988),
    Complex(57.62300453771084, -95.13882495530125),
    Complex(49.30886711217207, -102.55627992503798),
    Complex(41.505095712425266, -109.80973760934984),
    Complex(34.29665822148535, -116.87377036019856),
    Complex(27.75133477952216, -123.71459043749468),
    Complex(21.91843080359164, -130.29063733996253),
    Complex(16.827913864481246, -136.5536024978868),
    Complex(12.48999319425627, -142.4498401200803),
    Complex(8.895150636706308, -147.92209616761915),
    Complex(6.014621695177463, -152.91147376829161),
    Complex(3.801315206405911, -157.3595434447464),
    Complex(2.191150302390629, -161.2105007022443),
    Complex(1.1047799366797864, -164.4132720290794),
    Complex(0.44966155751382897, -166.92347324020744),
    Complex(0.12242770334713107, -168.70513119342874),
    Complex(0.01150255171237569, -169.73209090042374),
    Complex(-0.0000950783114673847, -169.98904445085157),
    Complex(-0.03182596239038418, -169.47213533231943),
    Complex(-0.20264839872203982, -168.1891109118144),
    Complex(-0.6280475461769198, -166.15901620997636),
    Complex(-1.417143635086449, -163.41144276360936),
    Complex(-2.6699447394779208, -159.985366436809),
    Complex(-4.474806548971296, -155.9276266348563),
    Complex(-6.906156923887331, -151.29111568712767),
    Complex(-10.022537062918564, -146.1327604809582),
    Complex(-13.865003992722224, -140.51138815880816),
    Complex(-18.455930962930772, -134.48557339816068),
    Complex(-23.79823338085903, -128.11156620883997),
    Complex(-29.87503834863011, -121.4413962187418),
    Complex(-36.649805886538466, -114.52124217483473),
    Complex(-44.066899764364535, -107.39014414253481),
    Complex(-52.05259574531458, -100.07912109539092),
    Complex(-60.516505202539804, -92.61073885404976),
    Complex(-69.35338271693288, -84.99915339325584),
    Complex(-78.44527761717661, -77.25063322188208),
    Complex(-87.66398167309598, -69.36454275244573),
    Complex(-96.87371847535402, -61.33474724018008),
    Complex(-105.9340145784748, -53.15137990436429),
    Complex(-114.70268837267419, -44.80289411498895),
    Complex(-123.0388899754411, -36.27830882027623),
    Complex(-130.80612425638162, -27.56954437192202),
    Complex(-137.8751894550298, -18.673739096114573),
    Complex(-144.1269657134623, -9.595434711733073),
    Complex(-149.4549911818757, -0.34852118040765934),
    Complex(-153.7677680909732, 9.042161239013403),
    Complex(-156.99074721377946, 18.539653285820883),
    Complex(-159.06794632606568, 28.094216144292893),
    Complex(-159.9631664576088, 37.64323458989423),
    Complex(-159.66077872235604, 47.11171735606422),
    Complex(-158.16606412227236, 56.41340429413915),
    Complex(-155.50509872157178, 65.45246496814921),
    Complex(-151.72418676063808, 74.12574840549826),
    Complex(-146.88885439386917, 82.32551981898139),
    Complex(-141.0824265658625, 89.94259820308314),
    Complex(-134.40421886512877, 96.86978969929865),
    Complex(-126.96738480455394, 103.00549632901534),
    Complex(-118.89646667985323, 108.25736877924284),
    Complex(-110.32470477839796, 112.54586590246237),
    Complex(-101.39116510243934, 115.80758277707571),
    Complex(-92.23774981190257, 117.9982136886636),
    Complex(-83.00615719191828, 119.0950261465811),
    Complex(-73.83485905078186, 119.09873675169524),
    Complex(-64.85616303045991, 118.03469888971692),
    Complex(-56.19342537368404, 115.95333517246252),
    Complex(-47.95847628269131, 112.92977346442115),
    Complex(-40.249315201420146, 109.0626732689418),
    Complex(-33.14812726339442, 104.47225817450305),
    Complex(-26.719664908452295, 99.29759889617566),
    Complex(-21.01003044554364, 93.69321910326654),
    Complex(-16.045886310826702, 87.82512164936831),
    Complex(-11.834110143051056, 81.8663550399298),
    Complex(-8.361901787981804, 75.99225812350896),
    Complex(-5.597339175259112, 70.37553436248126),
    Complex(-3.4903699130045407, 65.18131508967271),
    Complex(-1.9742156445057457, 60.56237354920504),
    Complex(-0.9671569275823941, 56.65464812422591),
    Complex(-0.3746578392855746, 53.57322405976011),
    Complex(-0.09178186863474502, 51.40890849881286),
    Complex(-0.005844109752898451, 50.22551427089378)
};