package com.sharkversion.rong.sharkview;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;



import android.support.design.widget.TabLayout;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v4.view.ViewPager;
import android.support.v4.view.PagerAdapter;
import android.view.View;
import  android.widget.TextView;
import android.view.ViewGroup;
import java.util.List;
import java.util.ArrayList;
import android.view.LayoutInflater;
import android.widget.ListView;
import android.widget.ArrayAdapter;
import  java.util.*;

import  java.net.HttpURLConnection;
import java.io.*;
import  java.net.*;
import android.util.Log;

import java.net.HttpURLConnection;
import android.net.ConnectivityManager;
import 	android.net.NetworkInfo;
import android.os.AsyncTask;
import org.json.JSONObject;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.HashMap;

import android.widget.Toast;

import android.content.Intent;

import 	android.widget.SimpleAdapter;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.AdapterView;
import android.widget.RelativeLayout;

import  com.sharkversion.rong.sharkview.ListViewAdapter.customButtonListener;


public class MainView extends AppCompatActivity implements
        customButtonListener
{

    private ViewPager mViewPager;
    private View view1, view2, view3;//需要滑动的页卡
    private List<View> views;// Tab页面列表
    private ArrayList<String> titleList;

    private ListViewAdapter conAdp;
    private TabLayout tab;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main_view);

        tab = (TabLayout) findViewById(R.id.switchWidget);
        mViewPager = (ViewPager) findViewById(R.id.mainWidget);

        tab.addOnTabSelectedListener(new TabLayout.OnTabSelectedListener()
        {

            public void onTabSelected(TabLayout.Tab t){
                //viewPager.setCurrentItem(t.getPosition());
                mViewPager.setCurrentItem(t.getPosition());
            }
            public void onTabUnselected (TabLayout.Tab t){

            }
            public void onTabReselected (TabLayout.Tab t){

            }
        });


        initView();

        InitPage1();
        InitPage2();
        InitPage3();
        InitPage4();

        PagerAdapter pagerAdapter = new PagerAdapter() {


            public boolean isViewFromObject(View arg0, Object arg1) {
                return arg0 == arg1;
            }


            public int getCount() {
                return views.size();
            }


            public void destroyItem(ViewGroup container, int position,
                                    Object object) {
                container.removeView(views.get(position));
            }


            public int getItemPosition(Object object) {
                return super.getItemPosition(object);
            }


            public CharSequence getPageTitle(int position) {
                return titleList.get(position);
            }


            public Object instantiateItem(ViewGroup container, int position) {
                container.addView(views.get(position));
                return views.get(position);
            }

        };
        mViewPager.setAdapter(pagerAdapter);
        mViewPager.addOnPageChangeListener(new ViewPager.OnPageChangeListener() {
               @Override
               public void onPageScrolled(int position, float positionOffset, int positionOffsetPixels) {

               }

               @Override
               public void onPageSelected(int position) {
                    //tab.set
                   tab.getTabAt(position).select();
               }

               @Override
               public void onPageScrollStateChanged(int state) {

               }
           }
        );
    //tab.setupWithViewPager(mViewPager);
        tab.addOnTabSelectedListener(new TabLayout.OnTabSelectedListener()
         {

             public void onTabSelected(TabLayout.Tab t){
                 //viewPager.setCurrentItem(t.getPosition());
                 mViewPager.setCurrentItem(t.getPosition());
             }
             public void onTabUnselected (TabLayout.Tab t){

             }
             public void onTabReselected (TabLayout.Tab t){

             }}
        );

/*
        RelativeLayout  r = (RelativeLayout ) findViewById( R.id.mainlayout);

        int a = r.getLayoutParams().height;

        int b = r.getLayoutParams().width;

        int c = tab.getLayoutParams().height;
        ViewGroup.LayoutParams params = mViewPager.getLayoutParams();
        params.height = 500 -60;
        mViewPager.setLayoutParams(params);*/

    }


    private void initView() {
        LayoutInflater lf = getLayoutInflater().from(this);
        view1 = lf.inflate(R.layout.page1, null);
        view2 = lf.inflate(R.layout.page2, null);
        view3 = lf.inflate(R.layout.page3, null);

        views = new ArrayList<View>();// 将要分页显示的View装入数组中
        views.add(view1);
        views.add(view2);
        views.add(view3);



    }

    private  void InitPage1()
    {
        ListView weblist = (ListView) view1.findViewById(R.id.weblist);

        List<Map<String, Object>> data1 = new ArrayList< Map<String, Object> > ();
        Map<String, Object> item = new HashMap<String, Object>();
        item.put("itemTitle","item1");
        item.put("itemPhoto",R.drawable.call);

        item.put("itemSummary","item1");
        item.put("itemAuthor","item1");
        item.put("itemPublishtime","item1");

        data1.add(item);

        item = new HashMap<String, Object>();
        item.put("itemTitle","  --------------CR50000n017--------------------------------");
        item.put("itemPhoto", R.drawable.email);
        item.put("itemSummary"," If a scroll area is used to display the contents of a widget that contains child widgets " +
                "arranged in a layout, it is important to realize that the size policy of the layout will also " +
                "determine the size of the widget. This is especially useful to know if you intend to dynamically change the " +
                "contents of the layout. In such cases, setting the layout's size constraint property to one");
        item.put("itemAuthor","item2");
        item.put("itemPublishtime","2017.2.05");

        data1.add(item);

        item = new HashMap<String, Object>();
        item.put("itemTitle","  --------------CR50000n017--------------------------------");
        item.put("itemPhoto", R.drawable.email);
        item.put("itemSummary"," If a scroll area is used to display the contents of a widget that contains child widgets " +
                "arranged in a layout, it is important to realize that the size policy of the layout will also " +
                "determine the size of the widget. This is especially useful to know if you intend to dynamically change the " +
                "contents of the layout. In such cases, setting the layout's size constraint property to one");
        item.put("itemAuthor","item2");
        item.put("itemPublishtime","2017.2.05");

        data1.add(item);

        item = new HashMap<String, Object>();
        item.put("itemTitle","  --------------CR50000n017--------------------------------");
        item.put("itemPhoto", R.drawable.email);
        item.put("itemSummary"," If a scroll area is used to display the contents of a widget that contains child widgets " +
                "arranged in a layout, it is important to realize that the size policy of the layout will also " +
                "determine the size of the widget. This is especially useful to know if you intend to dynamically change the " +
                "contents of the layout. In such cases, setting the layout's size constraint property to one");
        item.put("itemAuthor","item2");
        item.put("itemPublishtime","2017.2.05");

        data1.add(item);

        item = new HashMap<String, Object>();
        item.put("itemTitle","  --------------CR50000n017--------------------------------");
        item.put("itemPhoto", R.drawable.email);
        item.put("itemSummary"," If a scroll area is used to display the contents of a widget that contains child widgets " +
                "arranged in a layout, it is important to realize that the size policy of the layout will also " +
                "determine the size of the widget. This is especially useful to know if you intend to dynamically change the " +
                "contents of the layout. In such cases, setting the layout's size constraint property to one");
        item.put("itemAuthor","item2");
        item.put("itemPublishtime","2017.2.05");

        data1.add(item);

        item = new HashMap<String, Object>();
        item.put("itemTitle","  --------------CR50000n017--------------------------------");
        item.put("itemPhoto", R.drawable.email);
        item.put("itemSummary"," If a scroll area is used to display the contents of a widget that contains child widgets " +
                "arranged in a layout, it is important to realize that the size policy of the layout will also " +
                "determine the size of the widget. This is especially useful to know if you intend to dynamically change the " +
                "contents of the layout. In such cases, setting the layout's size constraint property to one");
        item.put("itemAuthor","item2");
        item.put("itemPublishtime","2017.2.05");

        data1.add(item);


        //创建简单适配器SimpleAdapter
        SimpleAdapter simpleAdapter = new SimpleAdapter(this, data1, R.layout.weblistitem,
                new String[] {"itemTitle","itemPhoto", "itemSummary", "itemAuthor", "itemPublishtime"},
                new int[] {R.id.title, R.id.photograph, R.id.summary, R.id.author, R.id.publishtime});

        //加载SimpleAdapter到ListView中
        weblist.setAdapter(simpleAdapter);
    }

    private  void InitPage2() {
        ListView techlist = (ListView) view2.findViewById(R.id.list_tech);
        List<Map<String, Object>> list111=new ArrayList<Map<String,Object>>();

        conAdp = new ListViewAdapter(this, list111);
        techlist.setAdapter(conAdp);
        conAdp.setCustomButtonListner(MainView.this);

        String my_str  = "http://sharknet.somee.com/info_group1.json";

        ImgAsyncTask task = new ImgAsyncTask();
       task.setCallBack(new ImgAsyncTask.callBack()
        {

            public void setItem(String name,String pic,String tel,JSONObject c) {
                Log.e("haha","get items");
                conAdp.addItem(name,tel,tel,pic, c );
                conAdp.notifyDataSetChanged();
            }
        });
        task.execute(my_str);/**/


        //处理Item的点击事件
        techlist.setOnItemClickListener(new AdapterView.OnItemClickListener(){
            public void onItemClick(AdapterView<?> parent, View view,int position, long id) {
                //info getObject = mlistInfo.get(position);   //通过position获取所点击的对象
                //int infoId = getObject.getId(); //获取信息id
               /// String infoTitle = getObject.getTitle();    //获取信息标题
               // String infoDetails = getObject.getDetails();    //获取信息详情

                //Toast显示测试
                Toast.makeText(MainView.this, "信息ID:"+"d",Toast.LENGTH_SHORT).show();
            }
        });


    }

    private  void InitPage3()
    {
        ListView techlist = (ListView) view3.findViewById(R.id.testlist);
        String[] values = new String[] { "Android", "iPhone", "WindowsMobile",
                "Blackberry", "WebOS", "Ubuntu", "Windows7", "Max OS X",
                "Linux", "OS/2", "Ubuntu", "Windows7", "Max OS X", "Linux",
                "OS/2", "Ubuntu", "Windows7", "Max OS X", "Linux", "OS/2",
                "Android", "iPhone", "WindowsMobile" };

        final ArrayList<String> list = new ArrayList<String>();
        for (int i = 0; i < values.length; ++i) {
            list.add(values[i]);
        }


        //创建简单适配器SimpleAdapter
        ArrayAdapter<String> adapter = new ArrayAdapter<String>( MainView.this,
                android.R.layout.simple_list_item_1, values);
        techlist.setAdapter(adapter);
/*
        techlist.setOnItemClickListener(new AdapterView.OnItemClickListener() {

            @Override
            public void onItemClick(AdapterView<?> parent, final View view,
                                    int position, long id) {
                final String item = (String) parent.getItemAtPosition(position);
                view.animate().setDuration(2000).alpha(0)
                        .withEndAction(new Runnable() {
                            @Override
                            public void run() {
                                list.remove(item);

                                view.setAlpha(1);
                            }
                        });
            }

        });*/
    }

    private  void InitPage4()
    {

    }


    public void onButtonClickListner(int position, String value) {
        Toast.makeText(MainView.this, "Button click " + value,
                Toast.LENGTH_SHORT).show();

        Intent ipp = new Intent(this, MainActivity.class);
        ipp.putExtra("Value1", "This value one for ActivityTwo ");
        ipp.putExtra("Value2", "This value two ActivityTwo");
        startActivity(ipp);

    }

}
