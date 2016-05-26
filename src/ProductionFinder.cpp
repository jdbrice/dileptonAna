#include "ProductionFinder.h"

const vector<int> ProductionFinder::runs_production_2014 = {15094020,15094019,15094018,15094017,15094016,15094015,15094014,15094013,15094012,15094011,15094010,15093054,15093053,15093052,15093051,15093050,15093049,15093048,15093047,15093046,15093045,15093044,15093043,15093018,15093017,15093016,15093015,15093013,15093012,15093011,15093010,15093009,15092018,15092017,15092016,15092015,15092014,15091046,15091045,15091044,15091043,15091042,15091041,15091040,15091039,15091038,15091037,15091036,15091035,15091034,15091033,15091032,15091031,15091030,15091005,15091004,15090068,15090067,15090066,15090065,15090064,15090063,15090062,15090060,15090059,15090058,15090057,15090056,15090055,15090054,15090053,15090036,15090010,15090008,15089049,15089048,15089047,15089046,15089045,15089044,15089043,15089042,15089041,15089040,15089039,15089038,15089037,15089036,15089034,15089033,15089032,15089031,15089030,15089029,15089028,15089020,15089010,15089009,15089008,15089007,15089006,15089005,15089004,15089002,15088069,15088068,15088067,15088066,15088065,15088064,15088063,15088046,15088043,15088042,15088041,15088039,15088038,15088037,15088036,15088020,15088019,15088017,15088015,15088014,15088013,15088008,15088007,15088006,15088005,15088004,15088003,15088002,15088001,15087059,15087058,15087057,15087056,15087055,15087052,15087050,15087049,15087047,15087046,15087043,15087042,15087041,15087040,15087039,15087038,15087037,15087036,15087035,15087034,15087022,15087021,15087020,15087019,15087018,15087017,15087016,15087015,15087014,15087013,15087012,15087011,15087010,15087009,15087008,15087007,15087006,15087005,15087004,15087003,15087002,15087001,15086082,15086081,15086080,15086079,15086078,15086077,15086076,15086075,15086074,15086073,15086072,15086069,15086068,15086067,15086066,15086065,15086064,15086063,15086062,15086061,15086060,15086059,15086058,15086055,15086054,15086053,15086052,15086051,15086050,15086046,15086045,15086044,15086043,15086042,15086018,15086017,15086016,15086015,15086014,15086013,15086012,15086011,15086010,15086009,15086008,15086007,15086006,15086005,15086004,15086003,15086002,15086001,15085115,15085114,15085022,15085021,15085020,15085019,15085018,15085017,15085016,15085015,15085014,15085013,15085012,15085011,15085010,15085009,15085008,15085007,15085006,15085005,15085004,15085003,15085002,15085001,15084093,15084092,15084091,15084090,15084089,15084070,15084069,15084068,15084067,15084066,15084064,15084063,15084062,15084061,15084060,15084059,15084058,15084055,15084054,15084053,15084052,15084051,15084040,15084039,15084038,15084037,15084036,15084035,15084034,15084033,15084032,15084031,15084030,15084029,15084028,15084027,15084026,15084025,15084024,15084022,15084021,15084020,15084011,15084010,15084009,15084008,15084007,15084006,15084005,15084004,15084003,15084002,15084001,15083062,15083061,15083041,15083038,15083036,15083031,15083030,15083029,15083028,15083027,15083026,15083025,15083024,15083023,15083021,15083019,15083017,15083015,15083014,15083012,15083011,15083010,15083009,15083008,15083007,15083005,15083004,15083003,15083002,15083001,15082075,15082074,15082073,15082071,15082069,15082067,15082066,15082065,15082064,15082063,15082062,15082060,15082059,15082058,15082057,15082056,15082055,15082053,15082052,15082051,15082050,15082049,15082035,15082031,15082030,15082028,15082025,15082024,15082023,15082022,15082021,15082018,15082017,15082016,15082014,15082013,15082012,15082011,15082010,15082009,15082008,15082007,15082006,15082005,15082004,15082001,15081052,15081046,15081044,15081043,15081042,15081041,15081038,15081037,15081036,15081034,15081033,15081029,15081028,15081027,15081026,15081025,15081024,15081023,15081022,15081021,15081020,15081017,15081016,15081015,15081014,15081013,15081012,15081011,15081010,15081009,15081008,15081007,15081006,15081005,15081004,15081003,15081002,15081001,15080064,15080063,15080062,15080061,15080060,15080059,15080058,15080057,15080056,15080055,15080054,15080053,15080052,15080045,15080044,15080043,15080042,15080041,15080039,15080038,15080037,15080036,15080035,15080032,15080029,15080024,15080016,15080015,15080014,15080013,15080012,15080011,15080010,15080009,15080008,15080007,15080006,15080005,15080004,15080003,15080002,15079063,15079062,15079061,15079060,15079059,15079058,15079057,15079056,15079052,15079051,15079050,15079049,15079048,15079047,15079046,15079042,15079041,15079027,15079026,15079025,15079024,15079023,15079022,15079021,15079020,15079019,15079018,15079017,15079016,15079015,15079014,15079013,15079011,15079010,15079009,15079008,15079007,15079004,15079003,15079002,15079001,15078113,15078112,15078111,15078110,15078109,15078108,15078107,15078104,15078103,15078075,15078074,15078073,15078071,15078069,15078064,15078063,15078021,15078020,15078019,15078018,15078017,15078016,15078015,15078014,15078013,15078012,15078011,15078009,15078008,15078007,15078006,15078005,15078004,15078003,15078002,15078001,15077080,15077079,15077070,15077069,15077067,15077066,15077065,15077063,15077062,15077061,15077060,15077059,15077057,15077056,15077055,15077054,15077053,15077052,15077051,15077050,15077049,15077048,15077047,15077046,15077045,15077044,15077043,15077042,15077039,15077036,15077035,15077033,15077032,15077022,15077020,15077019,15077018,15077017,15077016,15077015,15077014,15077012,15077011,15077010,15077009,15077008,15077007,15077006,15077004,15077003,15077002,15077001,15076109,15076108,15076105,15076102,15076101,15076099,15076096,15076095,15076094,15076092,15076091,15076090,15076089,15076088,15076087,15076086,15076085,15076084,15076082,15076081,15076080,15076079,15076078,15076077,15076076,15076074,15076073,15076072,15076070,15076068,15076057,15076056,15076048,15076047,15076046,15076045,15076044,15076043,15076042,15076041,15076040,15076038,15076037,15076036,15076035,15076034,15076033,15076032,15076031,15076030,15076028,15076026,15076024,15076023,15076022,15076019,15076016,15076015,15076014,15076013,15076012,15076011,15076010,15076009,15076008,15076007,15076006,15076005,15076004,15076003,15076002,15076001,15075098,15075097,15075095,15075094,15075093,15075092,15075089,15075088,15075085,15075084,15075083,15075079,15075074,15075073,15075071,15075065,15075063,15075062,15075061,15075060,15075059,15075058,15075057,15075056,15075055,15075051,15075045,15075024,15075023,15075022,15075021,15075020,15075019,15075018,15075017,15075016,15075015,15075014,15075013,15075012,15075011,15075010,15075009,15075008,15075007,15075006,15075005,15075001,15074104,15074070};
const vector<int> ProductionFinder::runs_production_low_2014 = {15166047,15166046,15166045,15166044,15166043,15166042,15166041,15166040,15166017,15166016,15166015,15166014,15166012,15166011,15166010,15165047,15165046,15165045,15165044,15165043,15165042,15165041,15165040,15164049,15164009,15164008,15164007,15164006,15164005,15164004,15164003,15164002,15163010,15163009,15163008,15163007,15163006,15162032,15162031,15162030,15162029,15162028,15162027,15162001,15161072,15161071,15161070,15161069,15161068,15161022,15161021,15161020,15161019,15161018,15161017,15161016,15160048,15160047,15160046,15160045,15160044,15160043,15160042,15160007,15160006,15160005,15160004,15159036,15159035,15159034,15159033,15159032,15159031,15159009,15159008,15159007,15159006,15159005,15158040,15158039,15158001,15157061,15157060,15157059,15157029,15157028,15157025,15157024,15157023,15157022,15157021,15156024,15156023,15156022,15156021,15156020,15156019,15154024,15154023,15154022,15154021,15154020,15154003,15154002,15154001,15153058,15153057,15153056,15153055,15153054,15153053,15153052,15153051,15153022,15153020,15153019,15153018,15153017,15153016,15153015,15153014,15152054,15152053,15152052,15152051,15152050,15152020,15152018,15152017,15152016,15152015,15151056,15151055,15151054,15151053,15151052,15151051,15151050,15151024,15151023,15151022,15151021,15151020,15151019,15150064,15150063,15150061,15150060,15150059,15147015,15147014,15147013,15147012,15147011,15147010,15147009,15146062,15146061,15146060,15146059,15146026,15146025,15146023,15146020,15145024,15145023,15145022,15144060,15144058,15144056,15144055,15144054,15144018,15144017,15144015,15144014,15144013,15143041,15143040,15143039,15143038,15143037,15142025,15142024,15142023,15142022,15142021,15141013,15141012,15141011,15141010,15141009,15141008,15141007,15141006,15141005,15141004,15140037,15140036,15140035,15140034,15140033,15140032,15140031,15140030,15140029,15140007,15140006,15140005,15140004,15139026,15139025,15139024,15139023,15138075,15138074,15138073,15138072,15137039,15137038,15136017,15136016,15136015,15136014,15136013,15134010,15134009,15134008,15133021,15133020,15133019,15133018,15132038,15132037,15132036,15132035,15132019,15131053,15131052,15131051,15131050,15131014,15131013,15131012,15130048,15130047,15130046,15130045,15130011,15130010,15130009,15130008,15130007,15129022,15129018,15129017,15129016,15129015,15129014,15129013,15129012,15129011,15129010,15129009,15128033,15128032,15128031,15128030,15128029,15127013,15126054,15126053,15126052,15126051,15126023,15126022,15126021,15126020,15126019,15126018,15126017,15125007,15125006,15125004,15125003,15125002,15125001,15124063,15124044,15124043,15124042,15124041,15124040,15124010,15124009,15124008,15124007,15124006,15124005,15123037,15123036,15123035,15123033,15123028,15123027,15123011,15123010,15123009,15122049,15122045,15122044,15122043,15122042,15122011,15122010,15122009,15122008,15122007,15122006,15122005,15122004,15122003,15122002,15122001,15121078,15121077,15121062,15121019,15121018,15121017,15121016,15121015,15121014,15121013,15121012,15121011,15121010,15121009,15121008,15121007,15121006,15120011,15120010,15120009,15120008,15120007,15120006,15120005,15120004,15120003,15120002,15120001,15119065,15119036,15119035,15119015,15119014,15119013,15119012,15119011,15119010,15118024,15118023,15118022,15118021,15118020,15118019,15117070,15117069,15117068,15117067,15117066,15117005,15117004,15117003,15116042,15116041,15116040,15116039,15116038,15115088,15115087,15115086,15115085,15114058,15114057,15114056,15114055,15114054,15114053,15113001,15112031,15112030,15112029,15112028,15112008,15112007,15112006,15112005,15110035,15110034,15110033,15110032,15110031,15110013,15110012,15110011,15110010,15110009,15110008,15110007,15109046,15109045,15109044,15109043,15109042,15109041,15109040,15109039,15109038,15109014,15109013,15109012,15109011,15109010,15109009,15109008,15109007,15109006,15108028,15108027,15108025,15108024,15108023,15108022,15108020,15108019,15108018,15108017,15108016,15108001,15107090,15107089,15107088,15107087,15107015,15107014,15107013,15107012,15107011,15107010,15107009,15107008,15106011,15106010,15106009,15106008,15106007,15106006,15106005,15106003,15106002,15106001,15105073,15105072,15105071,15105070,15105069,15105068,15105033,15105032,15105031,15105030,15105029,15105028,15105027,15105026,15105025,15105024,15105023,15105022,15105008,15105007,15105006,15105005,15105004,15105003,15105002,15105001,15104070,15104069,15104068,15104067,15104066,15104024,15104023,15104022,15104021,15104020,15104019,15104018,15104017,15104016,15103063,15103062,15103061,15103060,15103031,15103030,15103029,15103028,15103027,15103026,15103025,15103024,15102060,15102059,15102058,15102057,15102056,15102055,15102026,15102024,15102023,15102022,15102021,15102020,15102019,15101023,15101022,15101021,15101020,15101019,15101018,15101017,15101016,15101015,15101014,15100103,15100102,15100101,15100100,15100040,15100039,15100038,15100037,15100036,15100035,15100033,15100032,15100031,15099093,15098042,15098039,15098038,15098037,15098036,15098035,15098029,15098005,15098004,15098003,15098002,15098001,15097066,15097065,15097064,15097063,15097062,15097061,15097060,15097059,15097058,15097057,15097056,15097055,15097054,15097053,15097051,15097050,15097049,15097047,15097046,15097045,15097044,15097043,15097042,15097041,15097040,15097039,15097038,15097036,15097035,15097034,15097033,15097013,15097012,15097011,15097010,15097009,15097008,15097007,15097006,15096032,15096031,15096030,15096029,15096028,15096027,15096026,15096025,15095028,15095027,15095026,15095025,15095024,15095023,15095022,15095021,15095020,15094068};
const vector<int> ProductionFinder::runs_production_mid_2014 = {15167014,15167013,15167012,15167011,15167010,15167009,15167008,15166039,15166038,15166037,15166036,15166035,15166034,15166033,15166032,15166031,15166030,15166029,15166009,15166008,15166007,15166006,15166005,15166004,15166003,15166002,15166001,15165059,15165058,15165057,15165056,15165039,15165038,15165037,15165036,15165035,15165034,15165033,15165032,15165031,15165030,15165029,15165028,15165027,15165026,15165006,15165005,15165004,15165003,15165002,15165001,15164071,15164070,15164069,15164068,15164067,15164048,15164047,15164046,15164045,15164044,15164043,15164042,15164041,15164040,15164039,15164037,15164036,15164035,15164034,15164033,15164001,15163062,15163061,15163060,15163059,15163058,15163057,15163056,15163055,15163054,15163035,15163034,15163033,15163032,15163030,15163029,15163028,15163027,15163026,15163025,15163024,15163023,15163022,15163005,15163004,15163003,15163002,15163001,15162055,15162054,15162053,15162052,15162051,15162050,15162049,15162048,15162047,15162026,15162025,15162024,15162023,15162022,15162021,15162020,15162019,15162018,15162017,15162016,15162015,15161067,15161066,15161065,15161064,15161063,15161062,15161061,15161060,15161059,15161056,15161052,15161051,15161050,15161015,15161014,15161013,15161012,15161011,15161010,15161009,15161008,15161007,15161006,15161005,15160041,15160040,15160039,15160038,15160037,15160036,15160035,15160034,15160033,15160003,15160002,15160001,15159055,15159054,15159053,15159052,15159051,15159050,15159049,15159048,15159047,15159046,15159045,15159030,15159029,15159028,15159027,15159026,15159025,15159024,15159023,15159022,15159021,15159004,15159003,15159002,15159001,15158070,15158068,15158067,15158066,15158065,15158064,15158063,15158062,15158038,15158037,15158036,15158035,15158034,15158033,15158032,15158031,15158030,15158029,15158028,15157058,15157057,15157056,15157055,15157054,15157053,15157052,15157051,15157050,15157049,15157048,15157020,15157019,15157018,15157017,15157016,15157015,15157014,15157013,15157012,15157011,15157010,15156017,15156016,15156015,15156013,15156012,15156009,15156008,15156007,15155010,15154019,15154018,15154017,15154016,15154015,15154014,15154013,15154012,15153050,15153049,15153048,15153047,15153046,15153045,15153044,15153043,15153042,15153041,15153040,15153013,15153012,15153011,15153010,15153009,15153008,15153007,15153006,15153005,15153004,15153003,15152049,15152048,15152047,15152046,15152045,15152044,15152043,15152042,15152041,15152040,15152039,15152038,15152037,15152014,15152013,15152012,15152011,15152010,15152009,15152008,15152007,15152006,15152005,15152004,15152003,15151049,15151048,15151047,15151046,15151045,15151044,15151043,15151042,15151041,15151040,15151039,15151038,15151037,15151018,15151017,15151016,15151015,15151014,15151013,15151012,15151011,15151010,15151009,15151008,15151007,15151006,15151005,15151004,15150062,15150058,15150056,15150055,15150054,15150053,15150051,15150049,15150048,15150047,15150045,15150044,15150043,15150042,15150041,15150040,15150039,15150031,15150030,15150029,15150027,15150026,15150025,15150024,15150023,15150021,15150019,15150015,15150014,15150005,15150004,15150003,15150002,15150001,15149076,15149075,15149074,15149073,15149072,15149071,15149070,15149069,15149017,15149016,15149015,15149014,15149013,15149012,15148011,15148010,15148009,15148008,15148007,15148006,15148005,15148004,15148003,15147042,15147041,15147033,15147032,15147031,15147030,15147029,15147028,15147027,15147008,15147007,15147006,15147005,15147004,15147003,15147002,15147001,15146058,15146057,15146056,15146055,15146054,15146052,15146051,15146050,15146049,15146017,15146013,15146010,15146009,15146008,15146007,15146006,15146005,15146004,15146003,15146002,15146001,15145039,15145038,15145037,15145030,15145021,15145020,15145019,15145018,15145017,15145016,15145015,15145014,15145013,15145012,15145011,15145010,15145009,15144070,15144052,15144049,15144047,15144046,15144044,15144043,15144040,15144039,15144012,15144011,15144010,15144009,15144008,15144007,15144006,15144005,15144004,15143036,15143035,15143034,15143033,15143032,15143001,15142018,15142017,15142016,15142015,15142014,15142013,15142012,15142011,15142010,15142009,15142008,15142007,15141003,15141002,15141001,15140055,15140054,15140053,15140052,15140051,15140050,15140028,15140027,15140025,15140024,15140023,15140022,15140021,15140020,15140019,15140018,15140003,15140002,15140001,15139052,15139051,15139050,15139049,15139048,15139047,15139046,15139045,15139044,15139022,15139021,15139020,15139019,15139018,15139017,15139016,15138071,15138070,15138069,15138068,15138067,15138066,15138065,15138064,15138063,15138062,15137037,15137036,15137035,15137034,15137033,15137032,15137015,15137014,15137013,15137012,15137011,15136042,15136041,15136040,15136039,15136038,15136012,15136011,15136010,15136009,15136008,15136007,15136006,15136005,15136004,15136003,15135016,15135015,15135014,15135013,15135012,15135011,15135010,15134063,15134062,15134061,15134060,15134059,15134058,15134057,15134007,15134006,15134005,15134004,15134003,15134002,15134001,15133056,15133045,15133044,15133043,15133042,15133041,15133040,15133039,15133038,15133037,15133036,15133015,15133014,15133013,15133012,15133011,15133010,15133009,15133008,15132034,15132033,15132032,15132031,15132030,15132029,15132028,15132026,15132018,15132017,15132016,15132015,15132014,15132013,15132012,15132011,15132010,15132009,15132008,15132007,15131049,15131048,15131047,15131046,15131045,15131044,15131043,15131042,15131041,15131040,15131011,15131010,15131009,15131008,15131007,15131006,15131005,15131004,15130044,15130043,15130042,15130041,15130040,15130038,15130037,15130006,15130005,15130004,15130003,15130002,15130001,15129052,15129051,15129050,15129008,15129007,15129006,15129005,15129004,15129003,15129002,15128028,15128027,15128026,15128025,15128024,15128023,15128022,15127012,15127011,15127010,15127009,15127008,15127007,15127006,15127005,15127004,15126050,15126049,15126048,15126047,15126046,15126045,15126044,15126043,15126042,15126016,15126015,15126014,15126013,15126012,15126011,15126010,15126009,15125067,15125066,15124062,15124061,15124060,15124059,15124058,15124057,15124056,15124039,15124038,15124037,15124036,15124035,15124034,15124033,15124032,15124031,15124029,15124028,15124004,15124003,15124002,15124001,15123054,15123053,15123052,15123051,15123050,15123026,15123025,15123024,15123023,15123022,15123021,15123020,15123019,15123008,15123007,15123006,15123005,15123004,15123003,15123002,15123001,15122065,15122064,15122063,15122062,15122041,15122039,15122037,15122036,15122035,15122034,15122033,15122032,15122031,15122030,15121076,15121075,15121072,15121071,15121070,15121069,15121068,15121067,15121066,15121065,15121064,15121063,15121005,15121004,15121003,15121002,15121001,15120117,15119064,15119063,15119062,15119060,15119059,15119058,15119057,15119034,15119033,15119032,15119031,15119030,15119029,15119028,15119027,15119026,15119025,15119009,15119008,15119001,15118066,15118065,15118064,15118063,15118062,15118061,15118018,15118017,15118016,15118015,15117065,15117064,15117063,15117062,15117061,15117060,15117059,15117058,15117001,15116068,15116062,15116061,15116060,15116059,15116037,15116036,15116035,15116034,15116033,15116032,15116031,15115084,15115083,15115082,15115081,15115080,15115079,15114052,15114051,15114050,15114049,15114048,15114047,15114046,15114009,15114008,15114007,15114006,15114005,15114004,15112052,15112051,15112050,15112049,15112048,15112047,15112046,15112027,15112026,15112025,15112024,15112023,15112004,15112003,15112001,15111068,15111067,15110053,15110052,15110051,15110050,15110030,15110029,15110028,15110027,15110026,15110005,15110004,15110003,15110002,15110001,15109065,15109064,15109063,15109062,15109061,15109037,15109036,15109035,15109034,15109033,15109032,15109031,15109003,15109002,15109001,15108080,15108079,15108078,15108015,15108014,15108013,15108012,15108011,15107086,15107085,15107084,15107083,15107082,15107007,15107006,15107005,15105067,15105066,15105065,15105064,15105063,15105021,15105020,15105019,15104065,15104064,15104063,15104062,15104060,15104015,15104014,15104013,15104012,15103059,15103058,15103057,15103056,15103055,15103023,15103022,15103021,15103020,15103019,15102053,15102052,15102051,15102050,15102049,15102048,15102047,15102046,15102044,15102043,15102042,15102041,15102018,15102017,15102016,15102015,15102014,15101051,15101013,15101012,15101011,15101010,15101009,15100030,15100029,15100026,15099003,15099002,15099001,15098077,15098076,15098075,15098028,15098027,15098026,15098025,15098024,15098023,15098022,15098021,15098020,15097032,15097031,15097030,15097029,15097028,15097027,15097026,15097025,15097024,15097023,15097005,15097004,15097002,15097001,15096060,15096059,15096050,15096024,15096023,15096022,15096021,15096020,15096019,15096018,15095052,15095051,15095050,15095049,15095048,15095047,15095046,15095019,15095018,15095017,15095016,15095015,15095001,15094073,15094072,15094071,15094070};
const vector<int> ProductionFinder::runs_production_high_2014 = {15167007,15167006,15167005,15167004,15167002,15167001,15166058,15166051,15166028,15166027,15166026,15166025,15166024,15166023,15166022,15166013,15165055,15165054,15165053,15165052,15165051,15165050,15165049,15165048,15165025,15165024,15165023,15165022,15165021,15165020,15165019,15165018,15165010,15165009,15165008,15165007,15164066,15164065,15164064,15164063,15164062,15164061,15164060,15164059,15164057,15164032,15164030,15164029,15164028,15164024,15164023,15164022,15164016,15163053,15163052,15163051,15163050,15163049,15163048,15163047,15163021,15163020,15163019,15163018,15163017,15163016,15162046,15162045,15162044,15162043,15162042,15162041,15162040,15162014,15162013,15162012,15162011,15162010,15162009,15162006,15162005,15162004,15162003,15161058,15161057,15161055,15161054,15161053,15161049,15161048,15161043,15161037,15161036,15161035,15161004,15161003,15161002,15161001,15160050,15160049,15160032,15160031,15160030,15160029,15160028,15160027,15160026,15160025,15160024,15160023,15160020,15159044,15159043,15159042,15159041,15159040,15159039,15159038,15159037,15159019,15159018,15159017,15159016,15159015,15159014,15159013,15158061,15158060,15158059,15158058,15158057,15158056,15158055,15158027,15158026,15158025,15158024,15158023,15157047,15157046,15157045,15157039,15157034,15157033,15157009,15157008,15157007,15157006,15157005,15157004,15157003,15156043,15156042,15156041,15156040,15156039,15156038,15156014,15156011,15156010,15156004,15156003,15156002,15156001,15155040,15155039,15155038,15155009,15155008,15155007,15155006,15155005,15155004,15155003,15154035,15154034,15154011,15154010,15154009,15154008,15154007,15154006,15153039,15153038,15153037,15153036,15153035,15153034,15153033,15153002,15153001,15152058,15152057,15152056,15152055,15152036,15152035,15152034,15152033,15152032,15152031,15152030,15152029,15152002,15152001,15151062,15151061,15151058,15151057,15151036,15151035,15151034,15151033,15151032,15151031,15151001,15150082,15150081,15150080,15150079,15150078,15150057,15150013,15150012,15150011,15150010,15150009,15150008,15149067,15149064,15149063,15149062,15149061,15149011,15149010,15149009,15149008,15149007,15149005,15148069,15148067,15148066,15148065,15148064,15148063,15148062,15148061,15148058,15148001,15147040,15147039,15147038,15147037,15147036,15147026,15147025,15147024,15147023,15147022,15147021,15146069,15146068,15146067,15146066,15146065,15146064,15146063,15146046,15146045,15146044,15146043,15146042,15146041,15146040,15146033,15145064,15145063,15145062,15145061,15145060,15145059,15145058,15145057,15145056,15145055,15145036,15145035,15145034,15145033,15145032,15145031,15145029,15145028,15145008,15145007,15145006,15145005,15145004,15145003,15145002,15145001,15144068,15144067,15144065,15144064,15144063,15144062,15144061,15144037,15144036,15144035,15144034,15144033,15144032,15144028,15144027,15144026,15144003,15144002,15144001,15143052,15143051,15143050,15143049,15143048,15143044,15143031,15143030,15143029,15143028,15143027,15143026,15143025,15143014,15143013,15143012,15143011,15143010,15143009,15143008,15142062,15142061,15142060,15142059,15142058,15142055,15142054,15142053,15142020,15142019,15142006,15142005,15142004,15142003,15142002,15142001,15141048,15141047,15141046,15140049,15140048,15140047,15140046,15140045,15140044,15140026,15140017,15140016,15140015,15140014,15140013,15140012,15140011,15140010,15140009,15139043,15139042,15139041,15139040,15139039,15139038,15139037,15139032,15139015,15139014,15139013,15139012,15139010,15139009,15139008,15139007,15139006,15139003,15139002,15139001,15138061,15138060,15138059,15138058,15138057,15138056,15138055,15138035,15138025,15138024,15138023,15138022,15138021,15138020,15138019,15138018,15138017,15138016,15138012,15138010,15137054,15137053,15137052,15137051,15137050,15137049,15137030,15137029,15137028,15137027,15137026,15137025,15137023,15137010,15137009,15137008,15137007,15137006,15137005,15137004,15137003,15137002,15136037,15136036,15136035,15136034,15136033,15136032,15136031,15136023,15136002,15136001,15135065,15135064,15135063,15135062,15135061,15135060,15135059,15135053,15135052,15135051,15135050,15135009,15135008,15135007,15135006,15135005,15135004,15135003,15134067,15134066,15134056,15134055,15134054,15134053,15134052,15134051,15134050,15134049,15133055,15133054,15133053,15133051,15133050,15133049,15133047,15133046,15133035,15133034,15133033,15133032,15133031,15133030,15133029,15133017,15133007,15133006,15133005,15133004,15133003,15133002,15133001,15132025,15132024,15132023,15132022,15132020,15132006,15132005,15132004,15132003,15132002,15132001,15131039,15131038,15131037,15131036,15131035,15131034,15131033,15131032,15131031,15131030,15131029,15131028,15131003,15131002,15131001,15130056,15130055,15130054,15130053,15130036,15130035,15130034,15130033,15130032,15130031,15130030,15130016,15130015,15130014,15130013,15130012,15129049,15129048,15129047,15129046,15129045,15129044,15129023,15129001,15128052,15128051,15128050,15128049,15128048,15128047,15128042,15128021,15128020,15128019,15128018,15128017,15128016,15128015,15128014,15127096,15127095,15127003,15127002,15127001,15126061,15126060,15126059,15126058,15126057,15126041,15126040,15126039,15126038,15126037,15126036,15126035,15126028,15126008,15126007,15126006,15126005,15126004,15126003,15126002,15126001,15125082,15125075,15125074,15125073,15125072,15125071,15125070,15125065,15125064,15125063,15125062,15125061,15125060,15125059,15125058,15124055,15124054,15124053,15124052,15124051,15124050,15124049,15124027,15124026,15124025,15124024,15124023,15124022,15124021,15124017,15124016,15124015,15124014,15124013,15124012,15124011,15123049,15123048,15123047,15123046,15123045,15123044,15123043,15123034,15123018,15123017,15123016,15123015,15123014,15123013,15123012,15122061,15122060,15122059,15122058,15122057,15122056,15122055,15122048,15122047,15122046,15122028,15122027,15122026,15122025,15122024,15122023,15122021,15122020,15122019,15122018,15122017,15122016,15122015,15121061,15121060,15121059,15121039,15120116,15120115,15120113,15120112,15120111,15120110,15120109,15120108,15120107,15120106,15120105,15120104,15119061,15119056,15119055,15119054,15119053,15119052,15119051,15119050,15119049,15119048,15119047,15119046,15119045,15119044,15119043,15119042,15119041,15119024,15119023,15119022,15119021,15119020,15119019,15119018,15119017,15118060,15118059,15118058,15118057,15118056,15118055,15118054,15118053,15118052,15118051,15118014,15118013,15118012,15118011,15118010,15118009,15118008,15118007,15118006,15118005,15118004,15118003,15118002,15118001,15117057,15117056,15117055,15117054,15117053,15117052,15117051,15117050,15117049,15117024,15117023,15117020,15117002,15116058,15116057,15116056,15116055,15116054,15116053,15116052,15116051,15116050,15116049,15116048,15116047,15116046,15116045,15116030,15116029,15116027,15116026,15116022,15116021,15116020,15116019,15116018,15116017,15116016,15116015,15116013,15116005,15116004,15116003,15116002,15116001,15115078,15115077,15115076,15115075,15115074,15115073,15115072,15115071,15115070,15115069,15115068,15115067,15115066,15115018,15115015,15115014,15115013,15115012,15115011,15115002,15114045,15114044,15114043,15114042,15114041,15114040,15114039,15114038,15114037,15114036,15114035,15114034,15114033,15114028,15114027,15114026,15114025,15114024,15114023,15114022,15114021,15114020,15114019,15114018,15114017,15114016,15114015,15114014,15114013,15114012,15114011,15114010,15114003,15114002,15114001,15113104,15113103,15113102,15113101,15113100,15113012,15113011,15113010,15113009,15113006,15113005,15113004,15113003,15113002,15112045,15112044,15112043,15112042,15112041,15112040,15112039,15112038,15112037,15112036,15112035,15112034,15112033,15112032,15112022,15112021,15112020,15112019,15112014,15112013,15112012,15112011,15112010,15112009,15111066,15111065,15111053,15111052,15111051,15111050,15111049,15111048,15111044,15111016,15111015,15111014,15111013,15111012,15111011,15111010,15111009,15111008,15111007,15111006,15111005,15111004,15111003,15111002,15111001,15110058,15110049,15110048,15110047,15110046,15110045,15110043,15110042,15110041,15110040,15110039,15110038,15110037,15110036,15110025,15110024,15110023,15110022,15110021,15110020,15110019,15110018,15110017,15110016,15110015,15110014,15109060,15109059,15109058,15109057,15109056,15109055,15109054,15109052,15109051,15109050,15109049,15109030,15109029,15109028,15109027,15109026,15109025,15109024,15109022,15109021,15109020,15109019,15109018,15109005,15109004,15108077,15108076,15108075,15108074,15108073,15108072,15108071,15108070,15108069,15108064,15108063,15108059,15108058,15108057,15108056,15108055,15108054,15108036,15108021,15108010,15108009,15108008,15108007,15108006,15108005,15108004,15108003,15108002,15107081,15107080,15107079,15107078,15107077,15107076,15107075,15107074,15107073,15107065,15107064,15107063,15107062,15107024,15107004,15107003,15107002,15107001,15106136,15106135,15106134,15106133,15106132,15106131,15106130,15106129,15105062,15105061,15105058,15105057,15105056,15105055,15105054,15105053,15105018,15105017,15105016,15105015,15105014,15105013,15105012,15105011,15105010,15105009,15104059,15104058,15104057,15104056,15104055,15104054,15104053,15104052,15104051,15104050,15104044,15104043,15104042,15104040,15104039,15104037,15104034,15104011,15104010,15104009,15104008,15104007,15104006,15104005,15104004,15104003,15104002,15104001,15103054,15103053,15103052,15103051,15103050,15103049,15103046,15103045,15103044,15103043,15103042,15103041,15103018,15103017,15103016,15103015,15103014,15103013,15103012,15103011,15103010,15103009,15103008,15103001,15102068,15102066,15102065,15102040,15102039,15102038,15102037,15102036,15102035,15102034,15102033,15102032,15102031,15102013,15102012,15102011,15102010,15102009,15102008,15102007,15102006,15102005,15102004,15102003,15101054,15101053,15101050,15101049,15101048,15101047,15101046,15101045,15101044,15101043,15101042,15101041,15101040,15101039,15101038,15101008,15101007,15101006,15101005,15101004,15101003,15101002,15101001,15100124,15100123,15100104,15100028,15100027,15100025,15100024,15100023,15100022,15100021,15100015,15100014,15100013,15100012,15100011,15100010,15100009,15100008,15098074,15098073,15098072,15098071,15098070,15098069,15098068,15098067,15098066,15098065,15098064,15098041,15098040,15098019,15098018,15098017,15098016,15098015,15098014,15098013,15098012,15098011,15098010,15098009,15098008,15098007,15098006,15097022,15097021,15097020,15097019,15097018,15097016,15097015,15097014,15096058,15096057,15096056,15096055,15096054,15096053,15096052,15096049,15096047,15096017,15096016,15096015,15096014,15096013,15096012,15096011,15096007,15095045,15095044,15095043,15095042,15095041,15095040,15095039,15095038,15095037,15095036,15095035,15095034,15095014,15095013,15095012,15095011,15095010,15095009,15095008,15095006,15095005,15095004,15094069,15094067,15094066,15094065,15094064,15094063,15094060,15094059,15094058,15094057,15094056,15094055,15094054,15094009,15094008,15094007,15094006,15094005,15094004,15094003,15094002,15094001,15093064,15093063,15093062,15093061,15093060,15093059,15093058,15093042,15093041,15093040,15093039,15093038,15093037,15093036,15093035,15093034,15093033,15093032,15093031,15093030,15093008,15093007,15093006,15093005,15093004,15093003,15093002,15093001,15092079,15092078,15092077,15092076,15092075,15092074,15092013,15092012,15092011,15092010,15092009,15092008,15092007,15092006,15092005,15092004,15092003,15091064,15091029,15091028,15091027,15091026,15091025,15091024,15091023,15091022,15091020,15091019,15091008,15091007,15091006,15091001,15090050,15090049,15090048,15090047,15090039,15090038,15090037,15090034,15090033,15090030,15090022,15090021,15090020,15090019,15090018,15090017,15090007,15090006,15090005,15090004,15090003,15090002,15090001,15089054,15089053,15089052,15089051,15089050,15089027,15089026,15089025,15089024,15089023,15089022,15088062,15088061,15088060,15088059,15088058,15088057,15088056,15088048,15088047,15088044};
map<int, string> ProductionFinder::production_map;