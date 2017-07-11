package com.sharkversion.rong.sharkapp;

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
        view2 = lf.inflate(R.layout.page2, null);

        View view4 = lf.inflate(R.layout.itemlay, null);


        ListView list = (ListView) view2.findViewById(R.id.conn);

        List<String> data = new ArrayList<String>();
        data.add("44");
        data.add("55");
        data.add("66");
        data.add("++");

        List<Map<String, Object>> list111=new ArrayList<Map<String,Object>>();
        for (int i = 0; i < 10; i++) {
            Map<String, Object> map=new HashMap<String, Object>();
            map.put("image", R.drawable.kinetic);
            map.put("title", "这是一个标题"+i);
            map.put("info", "这是一个详细信息" + i);
            list111.add(map);
        }

        list.setAdapter(new ListViewAdapter(this, list111));

       // list.setAdapter(adapter);
  /*       list.getItemsCanFocus();
*/

        view3 = lf.inflate(R.layout.page1, null);

        views = new ArrayList<View>();// 将要分页显示的View装入数组中
        views.add(view1);
        views.add(view2);
        views.add(view3);

        titleList = new ArrayList<String>();// 每个页面的Title数据
        titleList.add("wp");
        titleList.add("jy");
        titleList.add("jh");


        //String a = getJSON("http://date.jsontest.com/");
        //OpenHttp();
        Log.v("Good", "index=" + 6);
        Log.v("Good", "jj");
        boolean bNet =  checkNetworkConnection();
        if(bNet) {
            Log.v("Good", "Have internet");
            //new HTTPAsyncTask().execute("http://hmkcode.com/examples/index.php");
            new HTTPAsyncTask().execute("http://sharknet.somee.com/json.json");
        }
        else
            Log.v("Good", "Not Internet");
    }


    public String getJSON(String address){
        StringBuilder builder = new StringBuilder();

        try {
           URL url  = new URL(address);


            HttpURLConnection urlConnection = (HttpURLConnection) url.openConnection();
            try {
                urlConnection.setDoOutput(true);
                urlConnection.setChunkedStreamingMode(0);

                OutputStream out = new BufferedOutputStream(urlConnection.getOutputStream());
                //writeStream(out);

                //return out.toString();

               // InputStream in = new BufferedInputStream(urlConnection.getInputStream());
                //readStream(in);
            }
            catch (java.io.IOException e)
            {

            }
            finally {
                urlConnection.disconnect();
            }
        }
        catch (java.io.IOException e)
        {

        }

        return builder.toString();
    }

    public  String OpenHttp()
    {
        HttpURLConnection urlConnection = null;
        BufferedReader reader = null;

        // Will contain the raw JSON response as a string.
        String forecastJsonStr = null;

        try {
            // Construct the URL for the OpenWeatherMap query
            // Possible parameters are avaiable at OWM's forecast API page, at
            // http://openweathermap.org/API#forecast
            URL url = new URL("http://api.openweathermap.org/data/2.5/forecast/daily?q=94043&mode=json&units=metric&cnt=7");

            // Create the request to OpenWeatherMap, and open the connection
            urlConnection = (HttpURLConnection) url.openConnection();
            urlConnection.setRequestMethod("GET");
            urlConnection.connect();

            // Read the input stream into a String
            InputStream inputStream = urlConnection.getInputStream();
            StringBuffer buffer = new StringBuffer();
            if (inputStream == null)
            {
                // Nothing to do.
                return null;
            }
            reader = new BufferedReader(new InputStreamReader(inputStream));

            String line;
            while ((line = reader.readLine()) != null)
            {
                // Since it's JSON, adding a newline isn't necessary (it won't affect parsing)
                // But it does make debugging a *lot* easier if you print out the completed
                // buffer for debugging.
                buffer.append(line + "\n");
            }

            if (buffer.length() == 0) {
                // Stream was empty.  No point in parsing.
                return null;
            }
            forecastJsonStr = buffer.toString();
        } catch (IOException e)
        {
            Log.e("PlaceholderFragment", "Error ", e);
            // If the code didn't successfully get the weather data, there's no point in attemping
            // to parse it.
            return null;
        }
        finally
        {
            if (urlConnection != null)
            {
                urlConnection.disconnect();
            }
            if (reader != null)
            {
                try
                {
                    reader.close();
                } catch (final IOException e)
                {
                    Log.e("PlaceholderFragment", "Error closing stream", e);
                }
            }
        }
        return forecastJsonStr;
    }


    public boolean checkNetworkConnection() {
        ConnectivityManager connMgr = (ConnectivityManager)
                getSystemService(getBaseContext().CONNECTIVITY_SERVICE);

        NetworkInfo networkInfo = connMgr.getActiveNetworkInfo();
        boolean isConnected = false;
        if (networkInfo != null && (isConnected = networkInfo.isConnected())) {
            // show "Connected" & type of network "WIFI or MOBILE"
            //tvIsConnected.setText("Connected "+networkInfo.getTypeName());
            // change background color to red
            //tvIsConnected.setBackgroundColor(0xFF7CCC26);


        } else {
            // show "Not Connected"
            //tvIsConnected.setText("Not Connected");
            // change background color to green
            //tvIsConnected.setBackgroundColor(0xFFFF0000);
        }

        return isConnected;
    }


    private class HTTPAsyncTask extends AsyncTask<String, Void, String> {

        protected String doInBackground(String... urls) {

            // params comes from the execute() call: params[0] is the url.
            try {
                return HttpGet(urls[0]);
            } catch (IOException e) {
                return "Unable to retrieve web page. URL may be invalid.";
            }
        }
        // onPostExecute displays the results of the AsyncTask.

        protected void onPostExecute(String result) {
            //tvResult.setText(result);
            Log.v("Good", result);
        }
    }

    private String HttpGet(String myUrl) throws IOException {
        InputStream inputStream = null;
        String result = "";

        URL url = new URL(myUrl);

        // create HttpURLConnection
        HttpURLConnection conn = (HttpURLConnection) url.openConnection();

        // make GET request to the given URL
        conn.connect();

        // receive response as inputStream
        inputStream = conn.getInputStream();

        // convert inputstream to string
        if(inputStream != null)
            result = convertInputStreamToString(inputStream);
        else
            result = "Did not work!";

        return result;
    }

    private static String convertInputStreamToString(InputStream inputStream) throws IOException{
        BufferedReader bufferedReader = new BufferedReader( new InputStreamReader(inputStream));
        String line = "";
        String result = "";
        while((line = bufferedReader.readLine()) != null)
            result += line;

        inputStream.close();
        return result;

    }

}
