#include"graph.h"
#include"search.h"

void place_print(struct Graph *g) {
	char *str[1000], *tmp;
	char *str1[26][1000];
	char str2[26];
	int i, m = 0;
	int sum[26] = { 0 };
	int n;
	for (i = 0; i < 79; i++) {
		str[m++] = g->name[i];
		for (n = 0; n < g->sum[i]; n++) {
			str[m++] = g->sign[i][n];
		}
	}
	for (i = 0; i < m - 1; i++) {
		for (n = i + 1; n < m; n++) {
			if (strcmp(str[i], str[n]) < 0) {
				tmp = str[i];
				str[i] = str[n];
				str[n] = tmp;
			}
		}
	}
	str2[0] = 'Z';
	str2[1] = 'Y';
	str2[2] = 'X';
	str2[3] = 'W';
	str2[4] = 'T';
	str2[5] = 'R';
	str2[6] = 'Q';
	str2[7] = 'P';
	str2[8] = 'N';
	str2[9] = 'M';
	str2[10] = 'L';
	str2[11] = 'K';
	str2[12] = 'J';
	str2[13] = 'H';
	str2[14] = 'G';
	str2[15] = 'F';
	str2[16] = 'D';
	str2[17] = 'C';
	str2[18] = 'B';
	str2[19] = 'A';
	for (i = 0; i < m; i++) {
		if (strcmp(str[i], "杂") > 0)
			str1[0][sum[0]++] = str[i];
		else if (strcmp(str[i], "呀") > 0)
			str1[1][sum[1]++] = str[i];
		else if (strcmp(str[i], "下") > 0)
			str1[2][sum[2]++] = str[i];
		else if (strcmp(str[i], "哇") > 0)
			str1[3][sum[3]++] = str[i];
		else if (strcmp(str[i], "他") > 0)
			str1[4][sum[4]++] = str[i];
		else if (strcmp(str[i], "然") > 0)
			str1[5][sum[5]++] = str[i];
		else if (strcmp(str[i], "七") > 0)
			str1[6][sum[6]++] = str[i];
		else if (strcmp(str[i], "啪") > 0)
			str1[7][sum[7]++] = str[i];
		else if (strcmp(str[i], "那") > 0)
			str1[8][sum[8]++] = str[i];
		else if (strcmp(str[i], "吗") > 0)
			str1[9][sum[9]++] = str[i];
		else if (strcmp(str[i], "啦") > 0)
			str1[10][sum[10]++] = str[i];
		else if (strcmp(str[i], "卡") > 0)
			str1[11][sum[11]++] = str[i];
		else if (strcmp(str[i], "及") > 0)
			str1[12][sum[12]++] = str[i];
		else if (strcmp(str[i], "哈") > 0)
			str1[13][sum[13]++] = str[i];
		else if (strcmp(str[i], "胳") > 0)
			str1[14][sum[14]++] = str[i];
		else if (strcmp(str[i], "发") > 0)
			str1[15][sum[15]++] = str[i];
		else if (strcmp(str[i], "打") > 0)
			str1[16][sum[16]++] = str[i];
		else if (strcmp(str[i], "擦") > 0)
			str1[17][sum[17]++] = str[i];
		else if (strcmp(str[i], "吧") > 0)
			str1[18][sum[18]++] = str[i];
		else
			str1[19][sum[19]++] = str[i];
	}
	for (i = 19; i >= 0; i--) {
		printf("%c\n", str2[i]);
		for (n = 0; n < sum[i]; n++) {
			printf("%30s", str1[i][n]);
			if ((n + 1) % 4 == 0) {
				printf("\n");
			}
		}
		printf("\n");
		for (int k = 0; k < 80; k++) {
			printf("--");
		}
		printf("\n");
	}
}

void route_init(struct Graph *g) {
	{
		g->order[0] = 1;
		g->name[0] = "下沙江滨";
		g->sign[0][0] = "伊萨卡国际城";
		g->sign[0][1] = "学正小学";
		g->sign[0][2] = "世贸广场";
		g->sign[0][3] = "浙江五丰冷食有限公司";
		g->sign[0][4] = "博世包装技术有限公司";
		g->sum[0] = 5;
		g->order[1] = 1;
		g->name[1] = "云水";
		g->sign[1][0] = "金沙学府";
		g->sign[1][1] = "源隆商业大厦";
		g->sign[1][2] = "云水苑";
		g->sign[1][3] = "浙江省杭州第四中学";
		g->sign[1][4] = "文海中学";
		g->sum[1] = 5;
		g->order[2] = 1;
		g->name[2] = "文海南路";
		g->sign[2][0] = "浙江工商大学";
		g->sign[2][1] = "浙江经济职业技术学院";
		g->sign[2][2] = "浙江经贸职业技术学院";
		g->sign[2][3] = "浙江水利水电学院";
		g->sign[2][4] = "阳光创富中心";
		g->sum[2] = 5;
		g->order[3] = 1;
		g->name[3] = "文泽路";
		g->sign[3][0] = "浙江理工大学";
		g->sign[3][1] = "警官职业学院";
		g->sign[3][2] = "浙江育英职业技术学院";
		g->sign[3][3] = "杭州电子科技大学";
		g->sign[3][4] = "杭州曙江大酒店";
		g->sum[3] = 5;
		g->order[4] = 1;
		g->name[4] = "高沙路";
		g->sign[4][0] = "金沙城";
		g->sign[4][1] = "浙江澳亚生物工程研究所";
		g->sign[4][2] = "盈都五角广场";
		g->sign[4][3] = "下沙铭都雅苑";
		g->sign[4][4] = "中砂金座";
		g->sum[4] = 5;
		g->order[5] = 1;
		g->name[5] = "金沙湖";
		g->sign[5][0] = "杭州东部国际商务中心";
		g->sign[5][1] = "龙湖时代金沙天街";
		g->sign[5][2] = "上沙锦湖家园";
		g->sign[5][3] = "上沙永裕大厦";
		g->sign[5][4] = "中沙金座";
		g->sum[5] = 5;
		g->order[6] = 1;
		g->name[6] = "下沙西";
		g->sign[6][0] = "金沙湖公园";
		g->sum[6] = 1;
		g->order[7] = 1;
		g->name[7] = "临平";
		g->sign[7][0] = "金鑫大厦";
		g->sign[7][1] = "迎宾路";
		g->sign[7][2] = "临平新城";
		g->sign[7][3] = "联盟新区";
		g->sign[7][4] = "余杭区第一人民医院";
		g->sum[7] = 5;
		g->order[8] = 1;
		g->name[8] = "南苑";
		g->sign[8][0] = "华元欢乐城";
		g->sign[8][1] = "余之城";
		g->sign[8][2] = "花园尚峰轩";
		g->sign[8][3] = "临东路";
		g->sign[8][4] = "汀城路";
		g->sum[8] = 5;
		g->order[9] = 1;
		g->name[9] = "余杭高铁站";
		g->sign[9][0] = "翁梅立交桥";
		g->sum[9] = 1;
		g->order[10] = 1;
		g->name[10] = "翁梅";
		g->sign[10][0] = "东田怡丰城";
		g->sign[10][1] = "赤家庙";
		g->sum[10] = 2;
		g->order[11] = 1;
		g->name[11] = "乔司";
		g->sign[11][0] = "华荣城";
		g->sign[11][1] = "乔司文化大楼";
		g->sign[11][2] = "朗诗花漫里";
		g->sign[11][3] = "马家埠";
		g->sum[11] = 4;
		g->order[12] = 1;
		g->name[12] = "乔司南";
		g->sign[12][0] = "稼东路";
		g->sum[12] = 1;
		g->order[13] = 1;
		g->name[13] = "客运中心";
		g->sign[13][0] = "九堡三区";
		g->sign[13][1] = "蓝桥景苑";
		g->sign[13][2] = "金雅苑";
		g->sign[13][3] = "左邻右舍";
		g->sign[13][4] = "九洲芳园";
		g->order[14] = 5;
		g->sum[13] = 0;
		g->name[14] = "九堡";
		g->sign[14][0] = "金海城";
		g->sign[14][1] = "中澳大厦";
		g->sign[14][2] = "宝进钢材加工配送";
		g->sign[14][3] = "杭州鼎雅服饰有限公司";
		g->sign[14][4] = "杭州铂金臻品酒店";
		g->sum[14] = 5;
		g->order[15] = 1;
		g->name[15] = "九和路";
		g->sign[15][0] = "九和人家";
		g->sign[15][1] = "鑫牛大厦";
		g->sign[15][2] = "过渡房";
		g->sign[15][3] = "杭州赛雷森有限公司";
		g->sign[15][4] = "招商雍华府";
		g->sum[15] = 5;
		g->order[16] = 1;
		g->name[16] = "七堡";
		g->sign[16][0] = "杭州地铁集团";
		g->sign[16][1] = "绿城杨柳郡";
		g->sign[16][2] = "德胜互通";
		g->sum[16] = 3;
		g->order[17] = 14;
		g->name[17] = "彭埠";
		g->sign[17][0] = "三花国际大厦";
		g->sign[17][1] = "莲花桥";
		g->sign[17][2] = "新中宇维萨";
		g->sign[17][3] = "新和嘉苑";
		g->sign[17][4] = "中豪五星国际广场";
		g->sign[17][5] = "明月嘉苑";
		g->sign[17][6] = "杭州市职工文化中心";
		g->sum[17] = 7;
		g->order[18] = 14;
		g->name[18] = "火车东站";
		g->sum[18] = 0;
		g->order[19] = 1;
		g->name[19] = "闸弄口";
		g->sign[19][0] = "衣之家城市广场";
		g->sign[19][1] = "机神新村";
		g->sign[19][2] = "中国人民解放军第117医院";
		g->sign[19][3] = "杭州浙江省公安边防总队医院";
		g->sign[19][4] = "蓝天城市花园";
		g->sign[19][5] = "濮家公园";
		g->sign[19][6] = "沁园雅舍";
		g->sum[19] = 7;
		g->order[20] = 1;
		g->name[20] = "打铁关";
		g->sign[20][0] = "绍兴路";
		g->sign[20][1] = "五里塘苑";
		g->sign[20][2] = "润和紫庭花园";
		g->sign[20][3] = "杭州商业储运有限公司";
		g->sum[20] = 0;
		g->order[21] = 1;
		g->name[21] = "西湖文化广场";
		g->sign[21][0] = "环球中心";
		g->sign[21][1] = "武林外滩";
		g->sign[21][2] = "青园小区";
		g->sign[21][3] = "朝晖一区";
		g->sign[21][4] = "浙江省公安厅消防局";
		g->sum[21] = 5;
		g->order[22] = 1;
		g->name[22] = "武林广场";
		g->sign[22][0] = "杭州大厦";
		g->sign[22][1] = "仕海足球公园";
		g->sign[22][2] = "电信大楼";
		g->sign[22][3] = "浙江文化大厦";
		g->sign[22][4] = "杭州游泳馆";
		g->sign[22][5] = "杭州粮贸大厦";
		g->sign[22][6] = "杭州医药大楼";
		g->sign[22][7] = "耶稣堂弄";
		g->sign[22][8] = "天名大厦";
		g->sum[22] = 9;
		g->order[23] = 12;
		g->name[23] = "凤起路";
		g->sign[23][0] = "杭州凤起大厦";
		g->sign[23][1] = "二轻大厦";
		g->sign[23][2] = "凤麟社区";
		g->sign[23][3] = "广福公寓";
		g->sum[23] = 4;
		g->order[24] = 1;
		g->name[24] = "龙翔桥";
		g->sign[24][0] = "杭州市第一人民医院";
		g->sign[24][1] = "浙江胜利剧院";
		g->sign[24][2] = "利星广场";
		g->sign[24][3] = "杭州市文化中心";
		g->sign[24][4] = "杭州凯悦酒店";
		g->sign[24][5] = "杭州口腔医院";
		g->sign[24][6] = "五福里";
		g->sign[24][7] = "浙江省中医院";
		g->sum[24] = 8;
		g->order[25] = 1;
		g->name[25] = "定安路";
		g->sign[25][0] = "定安名都";
		g->sign[25][1] = "西湖创意谷";
		g->sign[25][2] = "耀江广厦公寓";
		g->sign[25][3] = "书香楼苑";
		g->sign[25][4] = "天源商务楼";
		g->sign[25][5] = "杭州前锦青年旅社";
		g->sign[25][6] = "涌金门社区";
		g->order[26] = 7;
		g->sum[25] = 7;
		g->name[26] = "城站";
		g->sign[26][0] = "浙江大学附属第一医院";
		g->sign[26][1] = "杭州红楼大酒店";
		g->sign[26][2] = "杭州红星文化大厦";
		g->sign[26][3] = "香榭商务大厦";
		g->sign[26][4] = "中闽大厦";
		g->sign[26][5] = "联银大厦";
		g->sum[26] = 6;
		g->order[27] = 1;
		g->name[27] = "鳌江路";
		g->sign[27][0] = "望江家园东园";
		g->sign[27][1] = "杭州汽车南站";
		g->sum[27] = 2;
		g->order[28] = 14;
		g->name[28] = "近江";
		g->sign[28][0] = "杭州电视台";
		g->sign[28][1] = "杭州市公安局";
		g->sign[28][2] = "近江四园";
		g->sign[28][3] = "杭州市妇产科医院门诊楼";
		g->sign[28][4] = "钱江新城望江公园";
		g->sum[28] = 5;
		g->order[29] = 1;
		g->name[29] = "江陵路";
		g->sign[29][0] = "武警医院";
		g->sign[29][1] = "滨江区人民政府";
		g->sign[29][2] = "聚光中心";
		g->sign[29][3] = "钱塘春晓花园";
		g->sign[29][4] = "中财大厦";
		g->sign[29][5] = "中化大厦";
		g->sign[29][6] = "浙江吉利控股集团公司";
		g->sign[29][7] = "海越大厦";
		g->sum[29] = 8;
		g->order[30] = 1;
		g->name[30] = "滨河路";
		g->sign[30][0] = "浙江省杭州市江南实验学校";
		g->sign[30][1] = "铂金时代";
		g->sign[30][2] = "瑞立中央花城";
		g->sign[30][3] = "东方郡东区";
		g->sign[30][4] = "迎春北苑";
		g->sign[30][5] = "温馨人家";
		g->sum[30] = 6;
		g->order[31] = 1;
		g->name[31] = "西兴";
		g->sign[31][0] = "滨安小区";
		g->sign[31][1] = "春波南苑";
		g->sign[31][2] = "云厦连园";
		g->sign[31][3] = "中天官河锦庭";
		g->sign[31][4] = "新东方国际科技中心";
		g->sum[31] = 5;
		g->order[32] = 1;
		g->name[32] = "滨康路";
		g->sign[32][0] = "滨江时代";
		g->sign[32][1] = "紫城国际商务中心";
		g->sign[32][2] = "瑞立东方花城";
		g->sum[32] = 3;
		g->order[33] = 1;
		g->name[33] = "湘湖";
		g->sign[33][0] = "第一世界休博园";
		g->sign[33][1] = "苏黎士小镇";
		g->sign[33][2] = "复兴寺";
		g->sign[33][3] = "奥兰多小镇";
		g->sign[33][4] = "揽亭苑";
		g->sum[33] = 5;
		g->order[34] = 4;
		g->name[34] = "浦沿";
		g->sign[34][0] = "金盛曼城";
		g->sign[34][1] = "回龙山";
		g->sign[34][2] = "杭州高新金盛科技园";
		g->sum[34] = 3;
		g->order[35] = 4;
		g->name[35] = "杨家墩";
		g->sign[35][0] = "浙江警察学院";
		g->sign[35][1] = "绿城巧园";
		g->sign[35][2] = "塘外俞家";
		g->sign[35][3] = "银爵世纪公寓";
		g->sum[35] = 4;
		g->order[36] = 4;
		g->name[36] = "中医药大学";
		g->sign[36][0] = "浙江中医药大学滨江学院";
		g->sign[36][1] = "杭州志成大酒店";
		g->sign[36][2] = "志成大厦";
		g->sign[36][3] = "天鸿君邑";
		g->sign[36][4] = "东方通信城";
		g->sign[36][5] = "东方通信科技园";
		g->sign[36][6] = "龙禧硅谷广场";
		g->sign[36][7] = "中恒世纪科技园";
		g->sum[36] = 8;
		g->order[37] = 4;
		g->name[37] = "联庄";
		g->sign[37][0] = "东冠创业大厦";
		g->sign[37][1] = "之江公寓";
		g->sign[37][2] = "天寓";
		g->sign[37][3] = "联庄三区";
		g->sign[37][4] = "景江苑";
		g->sign[37][5] = "碧水豪园";
		g->sum[37] = 6;
		g->order[38] = 4;
		g->name[38] = "水澄桥";
		g->sign[38][0] = "六和源";
		g->sign[38][1] = "民安苑";
		g->sign[38][2] = "白塔人家";
		g->sign[38][3] = "水澄花园南苑";
		g->sum[38] = 2;
		g->order[39] = 4;
		g->name[39] = "复兴路";
		g->sign[39][0] = "复兴北苑";
		g->sign[39][1] = "山南人家";
		g->sign[39][2] = "杭州市清河实验学校";
		g->sum[39] = 3;
		g->order[40] = 4;
		g->name[40] = "南星桥";
		g->sign[40][0] = "钱江国际商务中心";
		g->sign[40][1] = "赞成大厦";
		g->sign[40][2] = "海运国际大厦";
		g->sign[40][3] = "赞成太和广场";
		g->sign[40][4] = "凤凰城";
		g->sign[40][5] = "中针商务";
		g->sign[40][6] = "凤凰南苑";
		g->sign[40][7] = "杭州市凤凰小学";
		g->sign[40][8] = "杭州娃哈哈双语学校";
		g->sum[40] = 9;
		g->order[41] = 4;
		g->name[41] = "甬江路";
		g->sign[41][0] = "杭州市中级人民法院";
		g->sign[41][1] = "新绿园";
		g->sign[41][2] = "滨江阳光海岸";
		g->sign[41][3] = "杭州市胜利实验学校";
		g->sum[41] = 4;
		g->order[42] = 4;
		g->name[42] = "城星路";
		g->sign[42][0] = "杭州电信大厦";
		g->sign[42][1] = "尊宝大厦";
		g->sign[42][2] = "钱江国际时代广场";
		g->sign[42][3] = "杭州电信大楼";
		g->sign[42][4] = "钱江新城森林公园";
		g->sign[42][5] = "世包国际中心";
		g->sum[42] = 6;
		g->order[43] = 4;
		g->name[43] = "市民中心";
		g->sign[43][0] = "高德置地广场";
		g->sign[43][1] = "砂之船国际生活广场";
		g->sign[43][2] = "杭州城市规划展览馆";
		g->sign[43][3] = "杭州洲际酒店";
		g->sign[43][4] = "迪凯银座";
		g->sign[43][5] = "杭州大剧院";
		g->sign[43][6] = "杭州国际会议中心";
		g->sum[43] = 7;
		g->order[44] = 4;
		g->name[44] = "江锦路";
		g->sign[44][0] = "杭州来福士广场";
		g->sign[44][1] = "中国人寿大厦";
		g->sign[44][2] = "万银国际";
		g->sign[44][3] = "世纪花园";
		g->sign[44][4] = "东方君悦";
		g->sum[44] = 5;
		g->order[45] = 24;
		g->name[45] = "钱江路";
		g->sign[45][0] = "万象城";
		g->sign[45][1] = "新城国际花园";
		g->sign[45][2] = "悦玺";
		g->sign[45][3] = "钱江三苑";
		g->sign[45][4] = "柏悦酒店";
		g->sum[45] = 5;
		g->order[46] = 4;
		g->name[46] = "景芳";
		g->sign[46][0] = "新城时代广场";
		g->sign[46][1] = "杭州天虹购物中心";
		g->sign[46][2] = "景苑社区";
		g->sign[46][3] = "杭州市江干区人事局";
		g->sign[46][4] = "杭州市四季青小学";
		g->sign[46][5] = "绿城蔚蓝公寓";
		g->sign[46][6] = "江干区四季青五福中心幼儿园";
		g->sign[46][7] = "杭州市景芳中学";
		g->sign[46][8] = "江干区教师进修学校";
		g->sign[46][9] = "杭州国泰外语艺术学校";
		g->sum[46] = 10;
		g->order[47] = 4;
		g->name[47] = "新塘";
		g->sign[47][0] = "华辰银座酒店";
		g->sign[47][1] = "保利中央公园";
		g->sign[47][2] = "艮新立交桥";
		g->sign[47][3] = "杭发旅馆";
		g->sign[47][4] = "浙江气象科技楼";
		g->sign[47][5] = "杭州创意设计中心";
		g->sum[47] = 6;
		g->order[48] = 4;
		g->name[48] = "新风";
		g->sign[48][0] = "浙江汽配城";
		g->sign[48][1] = "天运花园";
		g->sign[48][2] = "万家花园";
		g->sum[48] = 3;
		g->order[49] = 2;
		g->name[49] = "良渚";
		g->sign[49][0] = "万科未来城";
		g->sign[49][1] = "东西大道";
		g->sign[49][2] = "融信澜天";
		g->sum[49] = 3;
		g->order[50] = 2;
		g->name[50] = "杜甫村";
		g->sign[50][0] = "永旺梦乐城";
		g->sign[50][1] = "起梦公园";
		g->sign[50][2] = "疏港公路";
		g->sign[50][3] = "万科未来之光";
		g->sum[50] = 4;
		g->order[51] = 2;
		g->name[51] = "白洋";
		g->sign[51][0] = "越秀星汇悦城";
		g->sign[51][1] = "杭州奥克斯缔逸城";
		g->sign[51][2] = "景溪北苑";
		g->sum[51] = 3;
		g->order[52] = 2;
		g->name[52] = "金家渡";
		g->sign[52][0] = "协安蓝郡";
		g->sign[52][1] = "亲亲家园";
		g->sign[52][2] = "中海金溪园";
		g->sign[52][3] = "铭雅苑";
		g->sign[52][4] = "西点铭雅幼儿园";
		g->sum[52] = 5;
		g->order[53] = 2;
		g->name[53] = "墩祥街";
		g->sign[53][0] = "幸福里";
		g->sign[53][1] = "兰韵天城";
		g->sign[53][2] = "都市水乡";
		g->sum[53] = 3;
		g->order[54] = 2;
		g->name[54] = "三墩";
		g->sign[54][0] = "首开国风美域";
		g->sign[54][1] = "浙江广播电视大学";
		g->sign[54][2] = "杭师院副高新疆部";
		g->sign[54][3] = "华东勘测设计研究院";
		g->sign[54][4] = "秀月家园";
		g->sum[54] = 5;
		g->order[55] = 2;
		g->name[55] = "虾龙圩";
		g->sign[55][0] = "报出他实验学校";
		g->sign[55][1] = "绿城紫金广场";
		g->sign[55][2] = "广宇西城美墅";
		g->sum[55] = 3;
		g->order[56] = 2;
		g->name[56] = "三坝";
		g->sign[56][0] = "学军小学";
		g->sign[56][1] = "浙江大学紫金港校区";
		g->sign[56][2] = "申悦国际";
		g->sign[56][3] = "同人精华大厦";
		g->sign[56][4] = "优盘时代大厦";
		g->sign[56][5] = "橡果酒店";
		g->sign[56][6] = "同人广成";
		g->sign[56][7] = "政苑小区";
		g->sign[56][8] = "耀江文鼎苑";
		g->sum[56] = 9;
		g->order[57] = 2;
		g->name[57] = "文新";
		g->sign[57][0] = "杭州绿城育华小学";
		g->sign[57][1] = "湖畔花园";
		g->sign[57][2] = "骆家庄";
		g->sign[57][3] = "桂花城";
		g->sum[57] = 4;
		g->order[58] = 2;
		g->name[58] = "丰潭路";
		g->sign[58][0] = "浙江财经大学文华校区";
		g->sign[58][1] = "益乐新村";
		g->sign[58][2] = "世纪新城";
		g->sign[58][3] = "嘉绿西苑";
		g->sign[58][4] = "嘉绿名苑";
		g->sum[58] = 5;
		g->order[59] = 2;
		g->name[59] = "古翠路";
		g->sign[59][0] = "浙江省立同德医院";
		g->sign[59][1] = "元茂大厦";
		g->sign[59][2] = "杭州市西湖区人民法院";
		g->sign[59][3] = "嘉绿莲苑";
		g->sign[59][4] = "嘉绿北苑";
		g->sum[59] = 1;
		g->order[60] = 2;
		g->name[60] = "学院路";
		g->sign[60][0] = "浙江工商大学教工路校区";
		g->sign[60][1] = "九莲社区花园西村";
		g->sign[60][2] = "杭州市钱塘外国语学校";
		g->sign[60][3] = "杭州市行知小学";
		g->sign[60][4] = "枫华府第";
		g->sign[60][5] = "浙江省教育考试院";
		g->sign[60][6] = "浙江省能源与核技术应用研究所";
		g->sum[60] = 7;
		g->order[61] = 2;
		g->name[61] = "沈塘桥";
		g->sign[61][0] = "浙江电信专修学院";
		g->sign[61][1] = "东软科技大厦";
		g->sign[61][2] = "温泉公寓";
		g->sign[61][3] = "邮电新村";
		g->sign[61][4] = "浙江省建工大厦";
		g->sign[61][5] = "杭州市艺术创作研究中心";
		g->sign[61][6] = "美莱商务大厦";
		g->sign[61][7] = "立新大厦";
		g->sign[61][8] = "杭州文晖中学";
		g->sign[61][9] = "杭磁宿舍";
		g->sum[61] = 10;
		g->order[62] = 2;
		g->name[62] = "武林门";
		g->sign[62][0] = "浙江省人民政府";
		g->sign[62][1] = "杭州市中医院";
		g->sign[62][2] = "地矿科技大楼";
		g->sign[62][3] = "浙江省财政厅";
		g->sign[62][4] = "天和大厦";
		g->sign[62][5] = "宏都商务楼";
		g->sign[62][6] = "浙江省地质勘查局机关办公楼";
		g->sign[62][7] = "景湖苑";
		g->sign[62][8] = "浙江省科技厅";
		g->sum[62] = 1;
		g->order[63] = 2;
		g->name[63] = "中河北路";
		g->sign[63][0] = "浙江省杭州高级中学";
		g->sign[63][1] = "中银大厦";
		g->sign[63][2] = "纬成大厦";
		g->sign[63][3] = "环北市场";
		g->sign[63][4] = "舟山大厦";
		g->sign[63][5] = "三华园小区";
		g->sign[63][6] = "环北服装大厦";
		g->sign[63][7] = "杭州中国丝绸城";
		g->sum[63] = 8;
		g->order[64] = 2;
		g->name[64] = "建国北路";
		g->sign[64][0] = "双牛大厦";
		g->sign[64][1] = "诚信大厦";
		g->sign[64][2] = "东园大楼";
		g->sign[64][3] = "东联大厦";
		g->sign[64][4] = "杭州国际假日酒店";
		g->sign[64][5] = "建国公寓";
		g->sign[64][6] = "凤起苑";
		g->sign[64][7] = "东园高层公寓";
		g->sign[64][8] = "凤栖大酒店";
		g->sum[64] = 9;
		g->order[65] = 2;
		g->name[65] = "庆菱路";
		g->sign[65][0] = "紫晶商务城";
		g->sign[65][1] = "庆春发展大厦";
		g->sign[65][2] = "庆春御府";
		g->sign[65][3] = "银桥大酒店";
		g->sign[65][4] = "爱民票务在线杭州店";
		g->sign[65][5] = "双菱小区";
		g->sign[65][6] = "滨江凯旋门";
		g->sign[65][7] = "浙江紫晶大酒店";
		g->sum[65] = 8;
		g->order[66] = 2;
		g->name[66] = "庆春广场";
		g->sign[66][0] = "百大绿城西子国际";
		g->sign[66][1] = "杭州市江干区人民政府";
		g->sign[66][2] = "邵逸夫医院";
		g->sign[66][3] = "西子联合";
		g->sign[66][4] = "采荷人家";
		g->sign[66][5] = "三新银座资募大厦";
		g->sign[66][6] = "金投金融大厦";
		g->sign[66][7] = "三新大厦";
		g->sum[66] = 8;
		g->order[67] = 2;
		g->name[67] = "钱江世纪城";
		g->sign[67][0] = "丽晶国际";
		g->sign[67][1] = "红剑国际中心";
		g->sign[67][2] = "保亿中心";
		g->sign[67][3] = "宝盛世纪中心";
		g->sign[67][4] = "天人大厦";
		g->sign[67][5] = "浙江商会大厦";
		g->sign[67][6] = "传化大厦";
		g->sign[67][7] = "绿都国金中心";
		g->sign[67][8] = "利二花苑";
		g->sum[67] = 9;
		g->order[68] = 2;
		g->name[68] = "盈丰路";
		g->sign[68][0] = "博地中心";
		g->sign[68][1] = "振泽左右办公世界";
		g->sign[68][2] = "望京空间艺术中心";
		g->sign[68][3] = "港丽望京";
		g->sign[68][4] = "大象国际中心";
		g->sign[68][5] = "杭州广建大厦";
		g->sign[68][6] = "龙达国际大厦";
		g->sum[68] = 7;
		g->order[69] = 2;;
		g->name[69] = "飞虹路";
		g->sign[69][0] = "顺发和美家";
		g->sign[69][1] = "滨江金色江南";
		g->sum[69] = 2;
		g->order[70] = 2;
		g->name[70] = "振宁路";
		g->sign[70][0] = "佳境天城";
		g->sign[70][1] = "丰盛大厦";
		g->sign[70][2] = "百富众望大厦";
		g->sign[70][3] = "佳境社区文化广场";
		g->sign[70][4] = "佳境天域幼儿园";
		g->sign[70][5] = "江南明城南区";
		g->sign[70][6] = "天林广场";
		g->sign[70][7] = "供销社小区";
		g->sum[70] = 8;
		g->order[71] = 2;
		g->name[71] = "建设三路";
		g->sign[71][0] = "万向一二三股份公司";
		g->sign[71][1] = "保登电子科技公司";
		g->sign[71][2] = "德意中兴广场";
		g->sign[71][3] = "绿都百瑞广场";
		g->sign[71][4] = "大成名座";
		g->sign[71][5] = "雷迪森财富中心";
		g->sign[71][6] = "中誉万豪广场";
		g->sum[71] = 7;
		g->order[72] = 2;
		g->name[72] = "建设一路";
		g->sign[72][0] = "东方一品";
		g->sign[72][1] = "欢腾国际售展中心";
		g->sign[72][2] = "浙江庆丰纺织印染有限公司";
		g->sign[72][3] = "萧山空间结构科技产业园";
		g->sign[72][4] = "杭州市萧山第五高级中学";
		g->sign[72][5] = "传华花园中心";
		g->sum[72] = 6;
		g->order[73] = 2;
		g->name[73] = "人民广场";
		g->sign[73][0] = "绿都世贸广场";
		g->sign[73][1] = "杭州市萧山区政府";
		g->sign[73][2] = "华润万象汇";
		g->sign[73][3] = "开元名都";
		g->sign[73][4] = "心意广场";
		g->sign[73][5] = "北干一苑";
		g->sum[73] = 6;
		g->order[74] = 2;
		g->name[74] = "杭发厂";
		g->sign[74][0] = "银隆百货";
		g->sign[74][1] = "旺角新城天地";
		g->sign[74][2] = "顺发旺角城";
		g->sum[74] = 3;
		g->order[75] = 3;
		g->name[75] = "人民路";
		g->sign[75][0] = "永兴公园";
		g->sign[75][1] = "杭州新世纪广场";
		g->sign[75][2] = "城厢幼儿园";
		g->sign[75][3] = "浙江开元萧山宾馆";
		g->sign[75][4] = "萧然大厦";
		g->sign[75][5] = "天姿假日酒店";
		g->sign[75][6] = "城市酒店";
		g->sum[75] = 7;
		g->order[76] = 2;
		g->name[76] = "潘水";
		g->sign[76][0] = "潘水苑";
		g->sign[76][1] = "南江公园";
		g->sign[76][2] = "潘水农贸市场";
		g->sign[76][3] = "潘水南苑幼儿园";
		g->sum[76] = 4;
		g->order[77] = 2;
		g->name[77] = "曹家桥";
		g->sign[77][0] = "开元广场";
		g->sign[77][1] = "柳桥南和城";
		g->sign[77][2] = "广元公寓";
		g->sign[77][3] = "广悦公寓";
		g->sign[77][4] = "绿都南江壹号";
		g->sign[77][5] = "大缘寺";
		g->sum[77] = 6;
		g->order[78] = 2;
		g->name[78] = "朝阳";
		g->sign[78][0] = "宝丽控股";
		g->sign[78][1] = "杭州斯坦精品酒店";
		g->sign[78][2] = "锦伟塑料";
		g->sum[78] = 3;
		for (int i = 0; i < 6; i++) {
			graph_set_edge(g, i, i + 1, 1);
		}
		graph_set_edge(g, 6, 13, 1);
		for (int i = 7; i < 33; i++) {
			graph_set_edge(g, i, i + 1, 1);
		}
		for (int i = 34; i < 41; i++) {
			graph_set_edge(g, i, i + 1, 1);
		}
		graph_set_edge(g, 28, 41, 1);
		graph_set_edge(g, 28, 42, 1);
		for (int i = 42; i < 48; i++) {
			graph_set_edge(g, i, i + 1, 1);
		}
		graph_set_edge(g, 18, 48, 1);
		for (int i = 49; i < 62; i++) {
			graph_set_edge(g, i, i + 1, 1);
		}
		graph_set_edge(g, 23, 62, 1);
		graph_set_edge(g, 23, 63, 1);
		for (int i = 63; i < 66; i++) {
			graph_set_edge(g, i, i + 1, 1);
		}
		graph_set_edge(g, 45, 66, 1);
		graph_set_edge(g, 45, 67, 1);
		for (int i = 67; i < 78; i++) {
			graph_set_edge(g, i, i + 1, 1);
		}
	}
}

int search(struct Graph *g, char *name) {
	{
		int m, n, i;
		int judge = 0;
		for (i = 0; i < g->v; i++) {
			if (strcmp(g->name[i], name) == 0) {
				judge = 1;
				break;
			}
			for (n = 0; n < g->sum[i]; n++) {
				if (strcmp(g->sign[i][n], name) == 0) {
					judge = 1;
					break;
				}
			}
			if (judge == 1) {
				break;
			}
		}
		if (judge == 1) {
			return i;
		}
		else {
			return -1;
		}
	}
}

void route_search(struct Graph *g, struct Judge *p, int u, int v, int sum, int n) {
	int i;
	if (p->m == 1) {
		return;
	}
	if (u == v) {
		if (sum != n) {
			p->judge[u] = 0;
			return;
		}
		else {
			p->m = 1;
			return;
		}
	}
	if (sum == n) {
		if (u != v) {
			p->judge[u] = 0;
			return;
		}
	}
	else {
		for (i = 0; i < g->v; i++) {
			if (matrix_get(&g->m, u, i) == 1) {
				if (p->judge[i] == 0) {
					p->judge[i] = 1;
					sum++;
					p->route[sum] = i;
					route_search(g, p, i, v, sum, n);
					if (p->m == 1) {
						return;
					}
					else {
						sum--;
					}
				}
			}
		}
		if (i == g->v) {
			p->judge[u] = 0;
			return;
		}
	}
}

void route_print(struct Graph *g, struct Judge *p, int sum,char *begin,char *aim) {
	int subway[4][40];
	int k = 0;
	int judge1 = 0, judge2 = 0, judge = 0;
	int n, m, t;
	int route[100], way[100][3], much[100];
	int num[4]={0}, sign[4];
	for (int i = 0; i <= sum; i++) {
		n = 0;
		m = g->order[i];
		while (m > 0) {
			way[i][n++] = m % 10;
			m /= 10;
		}
		much[i] = n;
	}
	n = 0;
	for (int i = 0; i < g->v; i++) {
		if (strcmp(begin, g->name[i]) == 0) {
			judge1 = 1;
		}
		if (strcmp(aim, g->name[i]) == 0) {
			judge2 = 1;
		}
		if (judge1 == 1 && judge2 == 1) {
			break;
		}
	}
	if (judge1 == 0) {
		printf("%s->", begin);
	}
	for (int i = 0; i <= sum; i++) {
		printf("%s", g->name[p->route[i]]);
		if ((i < sum) && (p->route[i] == 23 || p->route[i] == 45 || p - route[i] == 28)&&(i>0)) {
			if (g->order[p->route[i - 1]] != g->order[p->route[i + 1]]) {
				printf("（换乘）");
			}
		}
		else if ((i + 1 < sum) && ((p->route[i] == 17 && p->route[i + 1] == 18) || (p->route[i] == 18 && p->route[i] == 17) && (i > 0))) {
			if (g->order[p->route[i - 1]] != g->order[p->route[i + 2]]) {
				printf("（换乘）");
			}
		}
		if (i != sum) {
			printf("->");
		}
		if ((i + 1) % 15 == 0) {
			printf("\n");
		}
	}
	if (judge2 == 0) {
		printf("->%s", aim);
	}
	printf("\n\n\n");
}