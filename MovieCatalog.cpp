#include"MovieCatalog.h"
#include"movie.h"
MovieCatalog::MovieCatalog()
{
    Movie* movieList[8];
    movieList[0]=new Movie(1,"X战警：逆转未来","布莱恩·辛格","休·杰克曼/迈克尔·法斯宾德",120,129,"动作/科幻","故事的设定发生在当下，变种人族群遭到了前所未有的毁灭性打击，而这一切的根源是“魔形女”瑞文...");
for(int i=1001;i<1003;i++){
     Session temp(i,"2015/6/1"+std::to_string(i-1000),"17:30");
     movieList[0]->getSessionList().push_back(temp);
}
for(int k=0;k<movieList[0]->getSessionList().size();k++){
for(int i=1;i<=5;i++){
    for(int j=1;j<=8;j++){
        Seat temp(i,j);
        movieList[0]->getSessionList()[k].getSeatList().push_back(temp);
   }
  }
 }

 movieList[1]=new Movie(2,"澳门风云","王晶","周润发/谢霆锋/杜汶泽",90,93,"喜剧/动作","影片讲述的是外号“赢尽天下无敌手”的石一坚和他的朋友家人一起布下并利用局从犯罪集团的手中逃脱的故事");
for(int i=1001;i<1003;i++){
     Session temp(i,"2015/6/1"+std::to_string(i-1000),"17:30");
     movieList[1]->getSessionList().push_back(temp);
}
for(int k=0;k<movieList[1]->getSessionList().size();k++){
for(int i=1;i<=5;i++){
    for(int j=1;j<=8;j++){
        Seat temp(i,j);
        movieList[1]->getSessionList()[k].getSeatList().push_back(temp);
   }
  }
 }
 movieList[2]=new Movie(3,"冰雪奇缘","克里斯·巴克","克里斯汀·贝尔/伊迪娜·门泽尔",100,102,"动画/冒险","影片讲述一个严冬咒语令王国被冰天雪地永久覆盖，安娜和山民克里斯托夫以及他的驯鹿搭档组队出发，为寻找姐姐拯救王国展开一段冒险");
for(int i=1001;i<1003;i++){
     Session temp(i,"2015/6/1"+std::to_string(i-1000),"17:30");
     movieList[2]->getSessionList().push_back(temp);
}
for(int k=0;k<movieList[2]->getSessionList().size();k++){
for(int i=1;i<=5;i++){
    for(int j=1;j<=8;j++){
        Seat temp(i,j);
        movieList[2]->getSessionList()[k].getSeatList().push_back(temp);
   }
  }
 }
   movieList[3]=new Movie(4,"超凡蜘蛛侠2","马克·韦步","安德鲁·加菲尔德/艾玛·斯通",120,142,"科幻/奇幻","影片讲述了彼得·帕克的生活依然很忙，而格温毕业后考虑去牛津大学继续深造。“电光人”出现后，彼得的生活更不得安宁、、、");
for(int i=1001;i<1003;i++){
     Session temp(i,"2015/6/1"+std::to_string(i-1000),"17:30");
     movieList[3]->getSessionList().push_back(temp);
}
for(int k=0;k<movieList[3]->getSessionList().size();k++){
for(int i=1;i<=5;i++){
    for(int j=1;j<=8;j++){
        Seat temp(i,j);
        movieList[3]->getSessionList()[k].getSeatList().push_back(temp);
   }
  }
 }
   movieList[4]=new Movie(5,"催眠大师","陈正道","徐峥/莫文蔚",90,102,"剧情/悬疑","影片讲述了知名心理治疗师徐瑞宁和棘手的女病人任小妍之间发生的故事。");
for(int i=1001;i<1003;i++){
     Session temp(i,"2015/6/1"+std::to_string(i-1000),"17:30");
     movieList[4]->getSessionList().push_back(temp);
}
for(int k=0;k<movieList[4]->getSessionList().size();k++){
for(int i=1;i<=5;i++){
    for(int j=1;j<=8;j++){
        Seat temp(i,j);
        movieList[4]->getSessionList()[k].getSeatList().push_back(temp);
   }
  }
 }
   movieList[5]=new Movie(6,"终结者：创世纪 ","阿兰·泰勒","艾米利亚·克拉克/杰·科特尼",100,130,"动作/科幻","超级电脑“天网”阻止人类抵抗领袖John Connor诞生的行动失败，时隔13年后，在“审判日”到来之前。。。");
for(int i=1001;i<1003;i++){
     Session temp(i,"2015/6/1"+std::to_string(i-1000),"17:30");
     movieList[5]->getSessionList().push_back(temp);
}
for(int k=0;k<movieList[5]->getSessionList().size();k++){
for(int i=1;i<=5;i++){
    for(int j=1;j<=8;j++){
        Seat temp(i,j);
        movieList[5]->getSessionList()[k].getSeatList().push_back(temp);
   }
  }
 }
   movieList[6]=new Movie(7,"人再囧途之泰囧","徐峥","徐峥/王宝强/黄渤",100,105,"喜剧","商业成功人士徐朗用了五年时间发明了一种叫“油霸”的神奇产品...");
for(int i=1001;i<1003;i++){
     Session temp(i,"2015/6/1"+std::to_string(i-1000),"17:30");
     movieList[6]->getSessionList().push_back(temp);
}
for(int k=0;k<movieList[6]->getSessionList().size();k++){
for(int i=1;i<=5;i++){
    for(int j=1;j<=8;j++){
        Seat temp(i,j);
        movieList[6]->getSessionList()[k].getSeatList().push_back(temp);
   }
  }
 }
 movieList[7]=new Movie(8,"夏日大作战","细田守","神木隆之介/谷村美月",120,114,"喜剧/动画","高中生小矶健二夏日的一天，他应邀来到美丽的学姐——阵内夏希的家乡打工。结果发现。。。");
for(int i=1001;i<1003;i++){
     Session temp(i,"2015/6/1"+std::to_string(i-1000),"17:30");
     movieList[7]->getSessionList().push_back(temp);
}
for(int k=0;k<movieList[7]->getSessionList().size();k++){
for(int i=1;i<=5;i++){
    for(int j=1;j<=8;j++){
        Seat temp(i,j);
        movieList[7]->getSessionList()[k].getSeatList().push_back(temp);
   }
  }
 }

    for(int i=0;i<8;i++){
    MovieList.push_back(*movieList[i]);
    }

}
