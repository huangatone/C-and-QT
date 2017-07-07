package com.sharkversion.rong.sharkapp;

import android.support.design.widget.TabLayout;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v4.view.ViewPager;
import android.support.v4.view.PagerAdapter;
import android.view.View;
import android.view.ViewGroup;
import java.util.List;
import java.util.ArrayList;
import android.view.LayoutInflater;


public class Main2Activity extends AppCompatActivity {


    private ViewPager mViewPager;
    private View view1, view2, view3;//需要滑动的页卡
    private List<View> views;// Tab页面列表
    private ArrayList<String> titleList;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        TabLayout tab = (TabLayout) findViewById(R.id.tab);
        mViewPager = (ViewPager) findViewById(R.id.view3);

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

        initView();
        //View rootView = inflater.inflate(R.layout.fragment_main, container, false);
        //TextView textView = (TextView) rootView.findViewById(R.id.section_label);
        //textView.setText(getString(R.string.section_format, getArguments().getInt(ARG_SECTION_NUMBER)));


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
               // weibo_button=(Button) findViewById(R.id.button1);
               // weibo_button.setOnClickListener(new OnClickListener() {

               //     public void onClick(View v) {
              //          intent=new Intent(ViewPagerDemo.this,WeiBoActivity.class);
              //          startActivity(intent);
              //      }
             //   });
                return views.get(position);
            }

        };
        mViewPager.setAdapter(pagerAdapter);
    }


    private void initView()
    {


        LayoutInflater lf = getLayoutInflater().from(this);
        view1 = lf.inflate(R.layout.page1, null);
        view2 = lf.inflate(R.layout.page1, null);
        view3 = lf.inflate(R.layout.page1, null);

        views = new ArrayList<View>();// 将要分页显示的View装入数组中
        views.add(view1);
        views.add(view2);
        views.add(view3);

        titleList = new ArrayList<String>();// 每个页面的Title数据
        titleList.add("wp");
        titleList.add("jy");
        titleList.add("jh");


    }

}
